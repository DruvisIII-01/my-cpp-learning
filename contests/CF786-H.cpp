#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    vector <int> cnt (31) ;
    int ans = a[1] ;
    for(int i = 1 ; i <= n ; i++) {
        ans &= a[i] ;
        int bt = 1 ;
        for(int t = 0 ; t < 31 ; t++){
            cnt[t] += ((bt & a[i]) == 0) ;
            bt <<= 1 ;
        }
    }
    //for(int i = 0 ; i < 31 ; i++) cout << cnt[i] << ' ' ;
    //cout << endl ;
    //for(int i = 0 ; i < 31 ; i++) if(cnt[i] > k) cnt[i] = -1 ;
    int bt = (int) 1 << 30 ;
    //int sum = 0 ;
    for(int t = 30 ; t >= 0 ; t--){
        if(!cnt[t] || cnt[t] > k) bt >>= 1 ;
        else {
            k -= cnt[t] ;
            if(k < 0) break ;
            else ans |= bt ;
            bt >>= 1 ;
        }
    }
    cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
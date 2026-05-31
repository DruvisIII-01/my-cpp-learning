#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
    int ans = 0, cnt0 = 0, cnt1 = 0, cnt2 = 0 ;
    for(int i = 1 ; i <= n ; i++){
        cnt0 += (a[i] == 0) ;
        cnt1 += (a[i] == 1) ;
        cnt2 += (a[i] == 2) ;
    }
    int M = max(cnt1, cnt2), m = min(cnt1, cnt2) ;
    ans = cnt0 + m + (M - m) / 3 ;
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
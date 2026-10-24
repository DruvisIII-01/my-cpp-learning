#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ; 
    vector<int> a(n + 1) ;
    vector<int> hsh(n + 1) ;

    int mx = -1 ;
    for(int t = 1 ; t <= n ; ++t){
        cin >> a[t] ;
        hsh[a[t]]++ ;
        mx = max(mx, a[t]) ;
    } int tmp_mx = mx ;
    if(!(hsh[mx] % 2)){
        cout << "YES" ;
        return ;
    }

    for(int t = tmp_mx - 1 ; t >= 1 ; t--){
        if(hsh[t]){
            if(mx - t <= k) {
                cout << "YES" ;
                return ;
            }else {
                mx = t ;
                if(!(hsh[mx] % 2)){
                    cout << "YES" ;
                    return ;
                }
            }
        }
    }
    cout << "NO" ;
    return ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
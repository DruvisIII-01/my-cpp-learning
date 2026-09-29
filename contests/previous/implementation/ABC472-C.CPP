#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int n, m, k ; cin >> n >> m >> k ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    vector<bool> vis(n + 1) ;
    int cur = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        if(cur + a[i] <= k) {
            cur += a[i] ;
            vis[i] = true ; 
            cout << "Yes" << endl ;
        }else cout << "No" << endl ;
        if(i - m + 1 >= 1){
            if(vis[i - m + 1]){
                cur -= a[i - m + 1] ;
                vis[i - m + 1] = false ;
            }
        }
    }
    return 0;
}
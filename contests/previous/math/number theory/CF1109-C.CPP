#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, x, y ; cin >> n >> x >> y ;
    int t = __gcd(x, y) ;

    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    vector <int> mv(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) 
    mv[a[i]] = abs(a[i] - i) ;

    bool ans = true ;
    for(int i = 1 ; i <= n ; ++i){
        if(mv[i] % t != 0){
            ans = false ;
            break ;
        }
    }
    if(ans) cout << "YES" ;
    else cout << "NO" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
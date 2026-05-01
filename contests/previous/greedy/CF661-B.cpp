#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    vector <int> b(n + 1) ;
    int mi_a = 1e9, mi_b = 1e9 ; 
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
        mi_a = min(mi_a, a[i]) ;
    }
    for(int i = 1 ; i <= n ; i++) {
        cin >> b[i] ;
        mi_b = min(mi_b, b[i]) ;
    }
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        ans += max(
            a[i] - mi_a, b[i] - mi_b 
        ) ;
    }cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
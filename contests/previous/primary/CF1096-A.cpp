#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int x, y ; cin >> x >> y ;
    int r1 = x % 2, r2 = y % 2 ;
    if(r1 == 1 && r2 == 1) cout << "NO" ;
    else cout << "YES" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
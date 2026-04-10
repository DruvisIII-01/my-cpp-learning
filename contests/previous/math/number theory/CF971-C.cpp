#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int x, y, k ; cin >> x >> y >> k ;
    int sx = (x + k - 1) / k, sy = (y + k - 1) / k ;
    if(sx > sy) cout << 2 * sx - 1 ;
    else cout << 2 * sy ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
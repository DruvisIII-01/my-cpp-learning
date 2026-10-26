#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int x, y, r ; cin >> x >> y >> r ;
    cout << x - r << ' ' << y ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
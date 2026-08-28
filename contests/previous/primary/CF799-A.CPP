#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, c, d ; cin >> a >> b >> c >> d ;
    int ans = (b > a) + (c > a) + (d > a) ;
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
#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, c, d ; cin >> a >> b >> c >> d ;
    int e1 = c - b, e2 = a + b, e3 = d - c ;
    if(e1 == e2 && e1 == e3) cout << 3 ;
    else if(e1 == e2 || e1 == e3 || e2 == e3) cout << 2 ;
    else cout << 1 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
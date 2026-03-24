#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int r ; cin >> r ;
    if(r >= 1900) cout << "Division " << 1 ;
    else if(r >= 1600) cout << "Division " << 2 ;
    else if(r >= 1400) cout << "Division " << 3 ;
    else cout << "Division " << 4 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
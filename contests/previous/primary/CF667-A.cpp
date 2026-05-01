#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b ; cin >> a >> b ;
    cout << (abs(a - b) + 9) / 10 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
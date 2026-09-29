#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, c ; cin >> a >> b >> c ;
    if(abs(a + c - b) >= abs(a - b)){
        a += c ;
        c = 0 ;
    }
    if(abs(b + c - a) <= abs(b - a)){
        b += c ;
        c = 0 ;
    }
    cout << abs(a - b) ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, c, d ; cin >> a >> b >> c >> d ;
    if(a == b && b == c && c == d){
        cout << "YES" ;
    }else cout << "NO" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
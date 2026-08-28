#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    string s ; cin >> s ;
    if(s[0] == 'a' || s[1] == 'b' || s[2] == 'c') cout << "YES" ;
    else cout << "NO" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
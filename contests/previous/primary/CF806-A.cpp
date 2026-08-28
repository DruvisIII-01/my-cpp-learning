#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    string s ; cin >> s ; 
    string s0 = "" ;
    for(char c : s){
        char ch = c ;
        if(c >= 'a' && c <= 'z') ch -= 32 ;
        s0 += ch ;
    }
    if(s0 == "YES") cout << "YES" ;
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
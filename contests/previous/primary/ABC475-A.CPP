#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    string s ; cin >> s ;
    for(int i = 0 ; i < s.size() ; ++i) {
        if(i == s.size() - 1) cout << s[i] ;
        else cout << s[i] << 'o' ;
    } 
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    string s ; cin >> s ;
    for(char ch : s){
        if(ch == 'A') cout << 'A' ;
        else cout << '.' ;
    }
    return 0;
}
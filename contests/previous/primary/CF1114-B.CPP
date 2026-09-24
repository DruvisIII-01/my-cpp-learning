#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ; s = '*' + s ;
    
    int dec = 0 ;
    for(int i = 2 ; i < n ; ++i){
        char ch1 = s[i - 1] ;
        char ch2 = s[i] ;
        char ch3 = s[i + 1] ;
        if(ch2 != ch1 && ch2 != ch3){
            if(ch1 == ch3) dec = max(dec, (int)2) ;
            else dec = max((int)1, dec) ;
        }
    }

    int diff = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        if(s[i] != s[i - 1]) diff++ ;
    }

    cout << diff - dec ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
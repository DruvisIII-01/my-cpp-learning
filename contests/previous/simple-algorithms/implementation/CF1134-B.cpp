#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string str ; cin >> str ; 
    char color = 'R' ;

    int cnt = 0 ; 
    for(char ch : str){
        if(ch != color) {
            color = ch ;
            cnt++ ;
        }//automatically switch
        if(color == 'R') color = 'B' ;
        else color = 'R' ;
    }cout << cnt ; 
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
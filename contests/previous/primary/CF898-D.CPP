#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ; 
    string s ; cin >> s ; s = '*' + s ;
    int index = 1, cnt = 0 ; 
    while(index <= n){
        if(s[index] == 'W') index++ ;
        else{
            cnt++ ;
            index += k ;
        }
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
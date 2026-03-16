#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;
    s = '*' + s ;
    int ans = -1 ;
    for(int i = 2 ; i <= n ; i++){
        if(s[i] == 'L') {
            ans = i ;
            break ;
        }
    }cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
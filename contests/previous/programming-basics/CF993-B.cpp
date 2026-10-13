#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    string s ; cin >> s ;
    string ans ;
    for(int i = s.size() - 1 ; i >= 0 ; i--){
        if(s[i] == 'q') ans += 'p' ;
        else if(s[i] == 'p') ans += 'q' ;
        else ans += 'w' ;
    }
    cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
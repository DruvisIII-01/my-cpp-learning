#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ;
    vector<int> hsh(26) ;
    int ans = 0 ;
    for(int i = 0 ; i < n ; ++i){
        char ch = s[i] ;
        if(!hsh[ch - 'A']) ans += 2 ;
        else ans++ ;
        hsh[ch - 'A']++ ;
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
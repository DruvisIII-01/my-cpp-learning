#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;
    string r = "" ;
    vector <bool> hsh(26) ;
    vector <int> idx(26) ;
    for(char ch : s) hsh[ch - 'a'] = true ;
    for(int i = 0 ; i < 26 ; i++) if(hsh[i]) r = r + (char) ('a' + i) ;
    int sz = (int) r.size() ;
    for(int i = 0 ; i < sz ; i++) idx[r[i] - 'a'] = i ;
    for(char ch : s) cout << r[sz - 1 - idx[ch - 'a']] ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
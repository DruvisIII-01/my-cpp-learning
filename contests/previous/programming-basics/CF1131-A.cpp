#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ; 
    string p, q ; cin >> p >> q ;
    vector<int> hsh(26) ;

    for(char ch : p) hsh[ch - 'a']++ ;
    for(char ch : q) hsh[ch - 'a']-- ;
    
    bool ans = true ; 
    for(int t = 'a' ; t <= 'z' ; ++t){
        int idx = t - 'a' ;
        if(t == 's' || t == 'x' || t == 'i'){
            if(hsh[idx] != 1) {
                ans = false ;
                break ;
            }
        }else if(hsh[idx] != 0){
            ans = false ;
            break ;
        }
    }if(ans) cout << "YES" ;
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
#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ; 
    vector <string> ss(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> ss[i] ;
    string ans = ss[1] ;
    for(int t = 0 ; t < m ; t++){
        string org = ans ;
        for(int i = 0 ; i < 26 ; i++){
            char ch = 'a' + i ;
            ans[t] = ch ;
            bool ok = true ;
            for(int j = 2 ; j <= n ; j++){
                int diff = 0 ;
                for(int k = 0 ; k < m ; k++){
                    if(ss[j][k] != ans[k]) diff++ ;
                }if(diff >= 2){
                    ok = false ; 
                    break ;
                }
            }if(ok) {
                cout << ans ;
                return ;
            }
        }
        ans = org ;
    }cout << '-' << 1 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
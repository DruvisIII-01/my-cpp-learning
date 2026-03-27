#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ;
    int mp[111][111] = {} ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            char ch ; cin >> ch ;
            if(ch == 'o') mp[i][j] = -1 ;
            else if(ch == '*') mp[i][j] = 1 ;
            else if(ch == '.') mp[i][j] = 0 ;
        }
    }
    cout << endl ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(mp[i][j] == -1){
                int above = 0 ;
                for(int k = i - 1 ; k >= 1 ; k--){
                    if(mp[k][j] == -1) break ;
                    above += mp[k][j] ;
                    mp[k][j] = 0 ;
                }
                for(int k = i - 1 ; k >= i - above ; k--){
                    mp[k][j] = 1 ;
                }
            }
        }
    }
    for(int j = 1 ; j <= m ; j++){
        if(mp[n][j] == -1) continue ;
        int above = 0 ;
        for(int k = n ; k >= 1 ; k--){
            if(mp[k][j] == -1) break ;
            above += mp[k][j] ;
            mp[k][j] = 0 ;
        }
        for(int k = n ; k >= n - above + 1 ; k--){
            mp[k][j] = 1 ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(mp[i][j] == 1) cout << '*' ;
            else if(mp[i][j] == 0) cout << '.' ;
            else if(mp[i][j] == -1) cout << 'o' ;
        }
        cout << endl ;
    }
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
        cout << endl ;
    }
    return 0;
}
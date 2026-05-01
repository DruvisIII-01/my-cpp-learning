#include <bits/stdc++.h>
using namespace std ;

#define int long long

int mp[111][111] ;

void solve(){
    int n ; cin >> n ;
    memset(mp, 0, sizeof(mp)) ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            char ch ; cin >> ch ;
            mp[i][j] = ch - '0' ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(j == n || i == n) continue ;
            if(mp[i][j]){
                if(!mp[i + 1][j] && !mp[i][j + 1]){
                    cout << "NO" ;
                    return ;
                }
            }
        }
    }cout << "YES" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
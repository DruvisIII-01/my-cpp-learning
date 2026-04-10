#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    bool mp[n + 1][2] = {} ;
    for(int i = 1 ; i <= n ; i++){
        int x, y ; cin >> x >> y ;
        mp[x][y] = true ;
    }int ans = 0 ;
    for(int x = 0 ; x <= n ; x++){
        if(mp[x][0] && mp[x][1]) ans += (n - 2) ;
    }for(int x = 1 ; x < n ; x++){
        if(mp[x][0] && mp[x - 1][1] && mp[x + 1][1]) ans++ ;
        if(mp[x][1] && mp[x - 1][0] && mp[x + 1][0]) ans++ ;
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
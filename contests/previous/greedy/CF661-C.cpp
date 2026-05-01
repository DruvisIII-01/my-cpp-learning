#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    sort(a.begin() + 1, a.begin() + n + 1) ;
    vector <int> team(101) ;
    for(int s = 100 ; s >= 0 ; s--){
        vector <int> vis(n + 1) ;
        int cnt = 0 ;
        for(int i = 1 ; i <= n ; i++){
            if(vis[i]) continue ;
            for(int j = i + 1 ; j <= n ; j++){
                if(vis[j]) continue ;
                if(a[i] + a[j] == s){
                    vis[j] = 1 ;
                    vis[i] = 1 ;
                    cnt++ ;
                    break ;
                }
            }
        }team[s] = cnt ;
    }
    int ans = 0 ;
    for(auto x : team) ans = max(ans, x) ;
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
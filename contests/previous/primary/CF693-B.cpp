#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 123) ;
    vector <bool> vis(n + 123) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    int mx = -1 ;
    for(int st = 1 ; st <= n ; st++){
        if(vis[st]) continue ;
        vis[st] = true ;
        int cur = a[st] ;
        int nx = st + a[st] ;
        while(nx <= n){
            if(vis[nx]) break ;
            vis[nx] = true ;
            cur += a[nx] ;
            nx += a[nx] ;
        }
        mx = max(mx, cur) ;
    }
    cout << mx ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
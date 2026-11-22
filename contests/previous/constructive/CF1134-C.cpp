#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    sort(a.begin() + 1, a.end()) ;
    int mx = a[n] ;

    vector<int> cons(n + 1) ; 
    for(int t = 1 ; t <= n ; ++t) {
        if(t & 1) cons[(t + 1) / 2] = a[t] ;
        else cons[n + 1 - t / 2] = a[t] ;  
    }

    vector<int> vis(n + 1) ;
    for(int t = 1 ; t <= n ; t++) {
        if(t == 1) vis[t] = true ;
        else if(cons[t] > cons[t - 1]) vis[t] = true ;
    }
    for(int t = n ; t >= 1 ; t--) {
        if(t == n) vis[t] = true ;
        else if(cons[t] > cons[t + 1]) vis[t] = true ;
    }
    int ans = 0 ;
    for(int t = 1 ; t <= n ; ++t) ans += vis[t] ;
    cout << ans << endl ;
    for(int t = 1 ; t <= n ; ++t) cout << cons[t] << ' ' ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
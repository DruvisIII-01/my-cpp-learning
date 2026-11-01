#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    map<int, int> cnt ;
    vector<int> vis ; 
    vector<int> v(n + 1) ;
    for(int t = 1 ; t <= n - 4 ; ++t) {
        int val = a[t] + a[t + 2] - a[t + 4] ;
        v[t] = val ;
        if(!cnt[val]) vis.push_back(val) ;
        cnt[val]++ ; 
    }
    //for(int x : vis) cout << x << ' ' << cnt[x] << endl ; 

    int ans = 0 ;
    vector<int> dt(4) ; dt = {-4, -2, 2, 4} ;
    for(int t = 1 ; t <= n - 4 ; ++t){
        int val = v[t], tmp = cnt[val] ;
        for(int i = 0 ; i < 4 ; ++i){
            int nt = t + dt[i] ;
            if(nt < 1 || nt > n - 4) continue ;
            if(v[nt] == val) tmp-- ;
        }
        ans += tmp - 1 ;
    }
    cout << ans / 2 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
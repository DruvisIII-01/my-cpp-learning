#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    vector<vector<int>> dp(n + 1, vector<int>(7)) ;
    for(int f = 1 ; f <= 6 ; ++f) dp[1][f] = (a[1] != f) ;
    for(int t = 2 ; t <= n ; ++t){
        for(int f = 1 ; f <= 6 ; ++f){
            int steps = (a[t] != f), mi = n + 114514 ;
            for(int g = 1 ; g <= 6 ; ++g){
                if(f + g == 7 || f == g) continue ;
                mi = min(mi, dp[t - 1][g]) ;
            }
            dp[t][f] = mi + steps ;
        }
    }

    int ans = n + 114514 ;
    for(int f = 1 ; f <= 6 ; ++f) ans = min(ans, dp[n][f]) ;
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
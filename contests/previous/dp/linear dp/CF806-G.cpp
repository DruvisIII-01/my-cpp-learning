#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    vector<vector<int>> dp(n + 1, vector<int>(33)) ;
    for(int i = 1 ; i <= n ; ++i) dp[i][0] = dp[i - 1][0] + a[i] - k ; 
    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 1 ; j <= min((int)32, i) ; ++j) {
            dp[i][j] = max(dp[i - 1][j] + (a[i] >> j) - k, 
            dp[i - 1][j - 1] + (a[i] >> j)) ;
        }
    }int mx = -114514 ;for(int i = 1 ; i <= n ; ++i)
    for(int j = 0 ; j <= min(n, (int)32) ; ++j) mx = max(mx, dp[i][j]) ;
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
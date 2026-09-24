#include <bits/stdc++.h>
using namespace std ;

#define int long long
void solve(){
    int n, m ; cin >> n >> m ; 
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
    vector <int> b(m + 1) ;
    for(int i = 1 ; i <= m ; ++i) cin >> b[i] ;
    sort(b.begin() + 1, b.end()) ;

    vector <int> sum(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) sum[i] = sum[i - 1] + a[i] ;
    vector<vector<int>> dp(m + 1, vector<int>(2, 0)) ;

    dp[0][0] = sum[n] ; //cout << dp[0][0] ;
    dp[0][1] = sum[n] ; //cout << dp[0][1] ;
    for(int i = 1 ; i <= m ; i++){
        //cout << endl ;
        int un = 2 * (sum[n] - sum[b[i]]) ;
        //cout << i << ' ' << b[i] << ' ' << sum[b[i]] <<endl ;

        dp[i][0] = min(dp[i - 1][0],
        un - dp[i - 1][1]) ;
        dp[i][1] = max(dp[i - 1][1],
        un - dp[i - 1][0]) ;

        //cout << dp[i][0] << ' ' << dp[i][1] << endl ;
    }

    cout << dp[m][1] ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
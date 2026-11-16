#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 998244353 ; 

void prt(vector<vector<int>>&a){
    for(int t = 1 ; t < a.size() ; ++t){
        cout << endl ; 
        for(int i = 1 ; i < a[t].size() ; ++i) {
            cout << a[t][i] << ' ' ;
        }cout << endl ;
    }
}

void solve(){
    int n, m ; cin >> n >> m ; 
    vector<vector<int>> dp(n + 1, vector<int>(m + 3)) ;
    vector<vector<int>> pre(n + 1, vector<int>(m + 3)) ;
    
    dp[1][1] = dp[1][2] = 1 ; 
    for(int t = 2 ; t <= n ; ++t) dp[t][1] = (int)1 ;
    for(int cur = 1 ; cur <= m + 2 ; ++cur){
        pre[1][cur] = pre[1][cur - 1] + dp[1][cur] ; 
        pre[1][cur] %= mod ;
    }

    for(int t = 2 ; t <= n ; ++t){
        dp[t][2] = pre[t - 1][2] ;
        for(int cur = 3 ; cur <= m + 2 ; ++cur){
            dp[t][cur] = pre[t - 1][cur] - pre[t - 1][cur / 2] + mod ;
            dp[t][cur] %= mod ; 
        }
        for(int cur = 1 ; cur <= m + 2 ; ++cur){
            pre[t][cur] = pre[t][cur - 1] + dp[t][cur] + mod ;
            pre[t][cur] %= mod ; 
        }
    }
    // cout << "dp: " ; 
    // prt(dp) ;
    // cout << "pre: " ; 
    // prt(pre) ;
    
    cout << dp[n][m + 2] ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
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

/* ######################################################################
 * 【题面与关键思路】Good Key, Bad Key
 * 题目链接：https://codeforces.com/problemset/problem/1703/G
 * 标签：难度 1600 | bitmasks,brute force,dp,greedy,math
 *
 * 关键思路：从左往右开箱，用坏钥匙会把之后所有收益除以 2；因为 log2(1e9) < 32，坏钥匙用超过 32 次后收益为 0，故 dp[i][j]（前 i 箱用 j 把坏钥匙）即可。关键是发现"j >= 32 后状态可合并"。
 * ###################################################################### */

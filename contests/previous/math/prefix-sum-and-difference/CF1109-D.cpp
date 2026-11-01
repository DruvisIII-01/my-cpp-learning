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

/* ######################################################################
 * 【题面与关键思路】Yaroslav and Productivity
 * 题目链接：https://codeforces.com/problemset/problem/2244/D
 * 标签：难度 1200 | constructive algorithms,dp,greedy,math,number theory
 *
 * 关键思路：读一个帖子会翻转其所有前缀（即把 b 的某前缀"翻转"），求能否让每个位置都被覆盖奇数次；按 b 排序后做奇偶两态的线性 DP。
 *
 * 本题已归档到 math/prefix-sum：前缀和作为 DP 状态的一部分。
 * ###################################################################### */

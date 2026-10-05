#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 3e5 + 22 ;

int dp[MAXN][3] ;

signed main() {
    int n, c ; cin >> n >> c ;
    vector <int> a(n + 1) ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
    dp[0][0] = 0 ;
    dp[0][1] = -1e18 ;
    dp[0][2] = -1e18 ;
    //不可以赋值为LLLONG_MIN，因为会向下溢出
    for(int i = 1 ; i <= n ; i++) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) ;
        dp[i][1] = max(dp[i - 1][0] + a[i] - c, dp[i - 1][2] + a[i]) ;
        dp[i][2] = dp[i - 1][1] ;
    }
    // for(int i = 1 ; i <= n ; i++) {
    //     cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] ;
    //     cout << endl ;
    // }
    int ans = max({dp[n][0], dp[n][1], dp[n][2]}); 
    cout << ans ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】P14746 下午茶时光
 * 题目链接：https://www.luogu.com.cn/problem/P14746
 * 标签：难度 洛谷 | dp, 分类讨论
 *
 * 关键思路：按位推三状态 DP（当前不在任何区间 / 在区间内且待结算 / 已结算），对每个点心的正负与 C 的代价分类转移；用后缀最大值或线段树优化到 O(n)。
 * ###################################################################### */

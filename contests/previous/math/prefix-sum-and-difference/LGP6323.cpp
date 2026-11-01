#include <bits/stdc++.h>
using namespace std ;

const int mod = 1e9 + 7 ;
const int MAXN = 1e3 + 111 ;
const int MAXC = 1e4 + 111 ;

//#define int long long

int dp[MAXC] ;
int pre[MAXC] ;

signed main() {
    int n, c ; cin >> n >> c ;
    dp[0] = 1 ;
    for(int i = 2 ; i <= n ; i++){
        pre[0] = dp[0] ;
        for(int j = 1 ; j <= c ; j++) {
            pre[j] = pre[j - 1] + dp[j] ;
            pre[j] %= mod ;
        }
        for(int j = 0 ; j <= c ; j++) {
            if(j - i >= 0) dp[j] = pre[j] - pre[j - i] + mod ;
            else dp[j] = pre[j] ;
            dp[j] %= mod ;
        }
    }
    cout << dp[c] ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】P6323 [COCI 2006/2007 #4] ZBRKA
 * 题目链接：https://www.luogu.com.cn/problem/P6323
 * 标签：难度 洛谷 提高+/省选- | dp, 前缀和优化
 *
 * 关键思路：dp[i][j] = 长度 i 排列恰有 j 个逆序对的方案数，dp[i][j] = sum_{k=0}^{i-1} dp[i-1][j-k]，用前缀和/滑动窗口把 O(n^2 c) 优化到 O(nc)。
 *
 * 本题已归档到 math/prefix-sum：dp 转移用前缀和压缩一维，是"前缀和优化 DP"的标准范例。
 * ###################################################################### */

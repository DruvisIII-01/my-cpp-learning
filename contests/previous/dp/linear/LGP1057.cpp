#include <bits/stdc++.h>
using namespace std ;

//#define int long long

const int MAXN = 1111 ;
const int MAXM = 1111 ;
int dp[MAXM][MAXN] ;

signed main() {
    int n, m ;
    cin >> n >> m ;
    dp[0][1] = 1 ;
    for (int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(j == 1) dp[i][j] = dp[i - 1][n] + dp[i - 1][2] ;
            else if(j == n) dp[i][j] = dp[i - 1][n - 1] + dp[i - 1][1] ;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] ;
        }
    }
    cout << dp[m][1] ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】P1057 [NOIP 2008 普及组] 传球游戏
 * 题目链接：https://www.luogu.com.cn/problem/P1057
 * 标签：难度 洛谷 普及- | dp, 递推, 环形dp
 *
 * 关键思路：dp[t][i] 表示传 t 次后球在 i 手上的方案数，dp[t][i] = dp[t-1][i-1] + dp[t-1][i+1]（下标按 n 取模成环）。
 * ###################################################################### */

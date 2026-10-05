#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 222 ;
const int MAXK = 10 ;
int dp[MAXN][MAXK] ;

signed main() {
    int n, k ; cin >> n >> k ;
    for(int i = 1 ; i <= n ; i++){
        for(int x = 1 ; x <= k ; x++){
            if(i < x) dp[i][x] = 0 ;
            else if(i == x) dp[i][x] = 1 ;
            //关键是所有x个箱子里都要放满苹果
            else dp[i][x] = dp[i - 1][x - 1] + dp[i - x][x] ;
        }
    }cout << dp[n][k] ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】P1025 [NOIP 2001 提高组] 数的划分
 * 题目链接：https://www.luogu.com.cn/problem/P1025
 * 标签：难度 洛谷 普及/提高- | dp, 整数划分
 *
 * 关键思路：dp[i][j] = dp[i-1][j-1] + dp[i-j][j]：把 i 分成 j 份，要么有一份为 1，要么每份都减 1。
 * ###################################################################### */

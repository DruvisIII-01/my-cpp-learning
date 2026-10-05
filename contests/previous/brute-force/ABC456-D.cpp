#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 998244353 ;

signed main() {
    string s ; cin >> s ; 
    int n = s.size() ;
    int dp[n + 12] = {} ;
    int end[n + 12] = {} ;
    int id0 = s[0] - 'a' ;
    dp[0] = 1 ;
    end[id0] = 1 ;

    int ans = 1 ;
    for(int i = 1 ; i < n ; i++){
        int idi = s[i] - 'a' ;
        int sum = end[0] + end[1] + end[2] ;
        sum = (sum + mod) % mod ;
        dp[i] = sum - end[idi] + 1 ;
        dp[i] = (dp[i] + mod) % mod ;
        ans = (ans + mod + dp[i]) % mod ;
        end[idi] = (end[idi] + dp[i] + mod) % mod ;
    }
    cout << ans ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Not Adjacent 2
 * 题目链接：https://atcoder.jp/contests/abc456/tasks/abc456_d
 * 标签：难度 ABC D | 计数/枚举
 *
 * 关键思路：统计没有"相邻字符相同"的子序列数：按段的末尾字符分类，用前缀和容斥统计以每个位置结尾的合法子序列数。
 * ###################################################################### */

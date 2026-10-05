#include <bits/stdc++.h>
using namespace std ;

//#define int long long

const int mod = 998244353 ;

signed main() {
    string s ; cin >> s ;
    int n = s.size() ;
    vector <int> dp(n + 1) ;
    dp[1] = 1 ;
    int ans = dp[1] ;
    s = '*' + s ;
    for(int i = 2 ; i <= n ; i++){
        if(s[i] == s[i - 1]) dp[i] = 1 ;
        else dp[i] = dp[i - 1] + 1 ;
        dp[i] %= mod ;
        ans += dp[i] ;
        ans %= mod ;
    }
    cout << ans ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】456
 * 题目链接：https://atcoder.jp/contests/abc456/tasks/abc456_b
 * 标签：难度 ABC B | 线性dp
 *
 * 关键思路：dp[i] 表示以第 i 位结尾的"同字符连续段"长度，累加 Σdp[i] 即所有字符相同的子串数。
 * ###################################################################### */

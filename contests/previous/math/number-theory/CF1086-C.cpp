#include <bits/stdc++.h>
using namespace std ;

// #define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> c(n+1), p(n+1) ;
    vector <double> r(n+1) ;
    for(int i = 1 ; i <= n ; i++)  {
        cin >> c[i] >> p[i] ;
        r[i] = 1.0-p[i]*1.0/100 ;
    }
    vector <double> dp(n+2) ;
    dp[n+1] = 0 ;
    for(int i = n ; i >= 1 ; i--) {
        dp[i] = max(1.0*c[i]+dp[i+1]*r[i], dp[i+1]) ;
    }
    printf("%.10lf", dp[1]) ;
    dp.clear();
    r.clear();
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
 * 【题面与关键思路】Stamina and Tasks
 * 题目链接：https://codeforces.com/problemset/problem/2208/C
 * 标签：难度 1300 | dp,greedy,math
 *
 * 关键思路：倒序期望/决策 DP：dp[i] = max(c[i] + dp[i+1]*r[i], dp[i+1])，其中 r[i] = 1 - p[i]/100 是"任务失败后仍能继续"的概率。
 * ###################################################################### */

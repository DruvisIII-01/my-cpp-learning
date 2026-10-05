#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    vector<int> sum(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) sum[t] = sum[t - 1] + (a[t] < t) ;
    vector<int> dp(n + 1) ;
    for(int t = 3 ; t <= n ; ++t){
        if(a[t] >= t) dp[t] = dp[t - 1] ;
        else if(!a[t]) dp[t] = dp[t - 1] ;
        else dp[t] = dp[t - 1] + sum[a[t] - 1] ;
    }cout << dp[n] ;
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
 * 【题面与关键思路】Yet Another Problem About Pairs Satisfying an Inequality
 * 题目链接：https://codeforces.com/problemset/problem/1703/F
 * 标签：难度 1300 | binary search, data structures, dp, greedy, sortings
 *
 * 关键思路：数对 (i,j) 满足 a[i] < i < a[j] < j 的个数：用前缀和 sum[] 统计满足 a[t] < t 的位置数，dp[t] = dp[t-1] + sum[a[t]-1]（若 a[t] < t）。
 * ###################################################################### */

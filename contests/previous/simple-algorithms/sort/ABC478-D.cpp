#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define pii pair<int, int>
signed main() {
    int n, q ; cin >> n >> q ;
    vector<vector<pii>> a(q + 2, vector<pii>()) ;
    for(int t = 1 ; t <= q ; ++t){
        int L, R, X ; cin >> L >> R >> X ;
        a[X].push_back({L, R}) ;
    }

    vector<int> dp(n + 2) ;
    for(int t = 1 ; t <= q ; ++t){
        if(!a[t].size()) continue ;
        sort(a[t].begin(), a[t].end()) ;
        
        // cout << "t = " << t << endl ;
        // for(int i = 0 ; i < a[t].size() ; ++i){
        //     printf("(%lld, %lld)\n", a[t][i].first, a[t][i].second) ;
        // }
        
        int fi = a[t][0].first ; 
        int se = a[t][0].second ; 
        for(int i = 0 ; i < a[t].size() ; ++i){
            if(a[t][i].first <= se)se = max(se, a[t][i].second) ;
            else {
                dp[fi]++ ;
                dp[se + 1]-- ;
                fi = a[t][i].first ;
                se = a[t][i].second ; 
            }
        }dp[fi]++ ;dp[se + 1]-- ;
    }
    // for(int i = 1 ; i <= n ; ++i) cout << dp[i] << ' ' ;
    // cout << '\n' ;

    vector<int> pre(n + 1) ;
    for(int i = 1 ; i <= n ; ++i){
        pre[i] = pre[i - 1] + dp[i] ;
        cout << pre[i] << ' ' ;
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Range Set Insertion Query
 * 题目链接：https://atcoder.jp/contests/abc478/tasks/abc478_d
 * 标签：难度 ABC D | 差分 / 区间合并
 *
 * 关键思路：把 n 次插入按时间 X 分组。对每个时间点，把该时间要插入的所有区间按左端点排序并合并成若干不相交区间，对每一段在差分数组上 +1/−1；最后做一遍前缀和，pre[i]、pre[i-1] 的差（即差分还原值）就是第 i 个位置被"不同时间点"插入的次数。
 * ###################################################################### */

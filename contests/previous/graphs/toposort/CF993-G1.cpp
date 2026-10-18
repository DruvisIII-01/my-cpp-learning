#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    vector<int> in(n + 1) ;
    vector<int> dp(n + 1, 1) ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        in[a[t]]++ ;
    }
    
    queue<int> que ;
    for(int t = 1 ; t <= n ; ++t) if(!in[t]) que.push(t) ;
    while(!que.empty()){
        int frt = que.front(), nxt = a[frt] ;
        in[nxt]-- ; 
        dp[nxt] = max(dp[nxt], dp[frt] + 1) ;
        
        if(!in[nxt]) que.push(nxt) ;
        que.pop() ;
    }

    int mx = -1 ;
    for(int t = 1 ; t <= n ; ++t) mx = max(mx, dp[t]) ;
    cout << mx + 1 ;
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
 * 【题面与关键思路】Medium Demon Problem (easy version)
 * 题目链接：https://codeforces.com/problemset/problem/2044/G1
 * 标签：难度 1700 | dfs and similar,graph matchings,graphs,implementation,trees
 *
 * 关键思路：函数图（每点出度 1）上求"最长链"：入度为 0 的点入队，出队时 dp[nxt] = max(dp[nxt], dp[frt] + 1)，统计全局最大 dp 再输出 mx + 1。与 hard 版（G2）的区别是这里取 max（最长路径），G2 是累加（路径条数）。
 * ###################################################################### */

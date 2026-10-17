#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    vector<int> in(n + 1) ;
    vector<int> dp(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        in[a[t]]++ ;
    }
    
    queue<int> que ;
    int mx = 0 ; 
    for(int t = 1 ; t <= n ; ++t) if(!in[t]) que.push(t) ;
    while(!que.empty()){
        int frt = que.front(), nxt = a[frt] ;
        in[nxt]-- ; 
        
        mx = max(mx, ++dp[frt]) ;
        dp[nxt] = dp[nxt] + dp[frt] ;

        if(!in[nxt]) que.push(nxt) ;
        que.pop() ;
    }cout << mx + 2 ;

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
 * 【题面与关键思路】Medium Demon Problem (hard version)
 * 题目链接：https://codeforces.com/problemset/problem/2044/G2
 * 标签：难度 1900 | dfs and similar, dp, dsu, graphs, implementation, trees
 *
 * 关键思路：函数图（每个点出度 1）上做拓扑排序式 DP：入度 0 入队，出队时 dp[nxt] += dp[frt] 累加"路径条数/深度"，同时用 mx 记录最大 dp。与 easy 版（G1）相比这里要累加而不是取 max，注意答案的偏移量。
 * ###################################################################### */

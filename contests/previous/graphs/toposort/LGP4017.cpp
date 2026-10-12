#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 664524 ;
const int MAXM = 664524 ;
const int mod = 80112002 ;
struct node{
    int to, next ;
}edge[MAXM] ;
int head[MAXN] ; int num = 0 ;
int in[MAXN] ; int out[MAXN] ;
void add(int u, int v){ 
    num++ ;
    edge[num].to = v ;
    edge[num].next = head[u] ;
    head[u] = num ;
}
signed main() {
    int n, m ; cin >> n >> m ;
    for(int t = 1 ; t <= m ; ++t){
        int a, b ; cin >> a >> b ;
        add(a, b) ; in[b]++ ; out[a]++ ;
    }//for(int i = 1 ; i <= n ; ++i) cout << in[i] << ' ' ;

    vector<int> dp(n + 1) ;
    queue<int> q ;
    for(int t = 1 ; t <= n ; ++t) {
        if(!in[t]) {
            q.push(t) ;
            dp[t] = 1 ;
        }
    }
    while(!q.empty()){
        int frt = q.front() ;
        // cout << frt << endl ;
        q.pop() ;
        for(int i = head[frt] ; i ; i = edge[i].next){
            int nxt = edge[i].to ;
            // cout << "nxt = " << nxt << endl ;
            dp[nxt] += dp[frt] ;
            dp[nxt] %= mod ;
            in[nxt]-- ;
            if(!in[nxt]) q.push(nxt) ;
        }
    }

    int ans = 0 ;
    for(int t = 1 ; t <= n ; ++t){
        if(!out[t]) {
            ans += dp[t] ;
            ans %= mod ;
        }
    }
    cout << ans ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】P4017 最大食物链计数
 * 题目链接：https://www.luogu.com.cn/problem/P4017
 * 标签：难度 洛谷 普及+/提高 | 拓扑排序, DAG 上 DP
 *
 * 关键思路：把食物链看成 DAG 上的路径：入度为 0 的是生产者（dp = 1），按拓扑序转移 dp[v] += dp[u]；答案是所有出度为 0 的点的 dp 之和，对 80112002 取模。
 * ###################################################################### */

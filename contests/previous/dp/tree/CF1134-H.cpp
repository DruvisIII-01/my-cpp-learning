#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define pii pair<int, int>
const int MAXN = 224524 ;
const int inf = 0x3f3f3f3f ;
vector<vector<pii>> info(MAXN + 1, vector<pii>()) ;

pii dfs_calc(int cur, int fa, vector<vector<int>>& adj){
    int cur_sum = 1 ;
    for(int nxt : adj[cur]){
        if(nxt == fa) continue ;
        int nxt_sum = dfs_calc(nxt, cur, adj).second ;
        info[cur].push_back({nxt, nxt_sum}) ;
        cur_sum += nxt_sum ;
    }return {cur, cur_sum} ;
}

int get(int cur, vector<vector<int>>& adj){
    int mx1 = 0, mx1_id = -1 ; 
    for(int t = 0 ; t < info[cur].size() ; ++t) {
        if(info[cur][t].second > mx1) {
            mx1 = info[cur][t].second ; 
            mx1_id = info[cur][t].first ; 
        }
    }
    //leaf_node
    if(mx1_id == -1) return mx1 ; 
    int mx2 = 0 ; 
    for(int t = 0 ; t < info[cur].size() ; ++t) {
        if(info[cur][t].first == mx1_id) continue ;
        mx2 = max(mx2, info[cur][t].second) ;
    }return max(mx2, get(mx1_id, adj)) ;
}

void solve(){
    int n ; cin >> n ; 
    vector<vector<int>> adj(n + 1) ;
    for(int t = 1 ; t <= n - 1 ; ++t) {
        int u, v ; cin >> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    //greedy
    dfs_calc(1, 0, adj) ;
    int s1 = 0 ;
    auto cmp_pii = [](const pii& p1, const pii& p2){
        return p1.second > p2.second ; 
    } ;
    sort(info[1].begin(), info[1].end(), cmp_pii) ;
    if(info[1].size() > 2) s1 = info[1][2].second ;
    int s2 = get(info[1][0].first, adj) ;
    if(info[1].size() > 1)
    s2 = max(s2, get(info[1][1].first, adj)) ;

    cout << n - max(s1, s2) ;
    
    //clear
    for(int t = 1 ; t <= n ; ++t) info[t].clear() ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】Extra Road
 * 题目链接：https://codeforces.com/problemset/problem/2290/H
 * 标签：难度 2290H（新场次，暂无 rating） | binary search, dfs, greedy, trees
 *
 * 关键思路：先 DFS 求出每棵子树的 size 与"最大儿子子树"，加一条额外边相当于把两个连通块连起来；对每个节点计算"去掉最大子树后剩余部分"与"最大子树"的较大者即该点的最优答案，再取全局最大。
 * ################################################################## */

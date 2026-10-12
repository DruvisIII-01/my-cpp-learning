#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define pii pair<int, int>
const int MAXN = 224524 ;
struct Node{
    int to, next, w ;
}edge[MAXN] ;
int head[MAXN] ; int num = 0 ;
void add(int u, int v, int w){
    num++ ;
    edge[num].to = v ;
    edge[num].next = head[u] ;
    edge[num].w = w ;
    head[u] = num ;
}

int dfn[MAXN] ; int DFN = 0 ;
int low[MAXN] ;
int stk[MAXN] ; int len = 0 ;
bool ins[MAXN] ; 
int scc[MAXN] ; int cnt = 0 ;
void tarjan(int x){
    DFN++ ;
    dfn[x] = low[x] = DFN ;
    
    ins[x] = true ;
    len++ ;
    stk[len] = x ;

    for(int i = head[x] ; i ; i = edge[i].next ){
        int y = edge[i].to ;
        if(!dfn[y]) {
            tarjan(y) ; 
            low[x] = min(low[x], low[y]) ;
        }else if(ins[y]) low[x] = min(low[x], dfn[y]) ; 
    }

    if(dfn[x] == low[x]){
        cnt++ ;
        scc[x] = cnt ;
        ins[x] = false ;
        while(dfn[stk[len]] != low[stk[len]]){
            scc[stk[len]] = cnt ;
            ins[stk[len]] = false ;
            len-- ;
        }len-- ;
    }
}
signed main() {
    int n, qwq ; cin >> n >> qwq ;
    vector<vector<pii>> G(n + 1, vector<pii>()) ;
    vector<array<int,3>> edges;
    while(qwq--){
        int t, u, v ; cin >> t >> u >> v ;
        add(u, v, t) ;
        G[u].push_back({v, t}) ;
        edges.push_back({u, v, t}) ;
    }
    for(int t = 1 ; t <= n ; t++) if(!dfn[t]) tarjan(t) ;

    for(int time = 1 ; time <= n ; ++time) {
        for(auto [v, t] : G[time]){
            if((scc[v] == scc[time]) && t) {
                cout << "No" ;
                return 0 ;
            }
        }
    }


    for(int t = 1 ; t <= n ; t++) G[t].clear() ;
    for(auto [u, v, t] : edges){
        if(scc[u] != scc[v]) 
        G[scc[u]].push_back({scc[v], t}) ;
    }

    vector<int> val(n + 1, 1) ;
    for(int time = cnt ; time >= 1 ; time--){
        for(auto [v, t] : G[time])
        val[v] = max(val[v], val[time] + t) ;
    }cout << "Yes" << '\n' ;
    for(int t = 1 ; t <= n ; ++t) cout << val[scc[t]] << ' ' ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】lt and le
 * 题目链接：https://atcoder.jp/contests/abc478/tasks/abc478_e
 * 标签：难度 ABC E | Tarjan SCC + DAG 上 DP
 *
 * 关键思路：把 t 看成边权、u→v 看成约束。先用 Tarjan 求 SCC：若某条 t=1 的边两端在同一 SCC 内则矛盾（输出 No）。否则缩点成 DAG，按 SCC 编号从大到小（Tarjan 的编号近似逆拓扑序）做 DP，val[v] = max(val[v], val[u] + t)，最后输出每个点所属 SCC 的值。
 * ###################################################################### */

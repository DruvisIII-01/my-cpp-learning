#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define pii pair<int, int>  
const int MAXN = 3333 ;
const int MAXM = 3333 ;
const int INF = LLONG_MAX / 4 ;
struct Node{
    int to ; 
    int next ;
    int wt ;
}edge[MAXM] ;
int head[MAXN] ; int num = 0 ;
void add(int u, int v, int w){
    num++ ;
    edge[num].to = v ;
    edge[num].next = head[u] ;
    edge[num].wt = w ;
    head[u] = num ;
}
int dis[MAXN] ;
signed main() {
    int n, m, s ; cin >> n >> m >> s ;
    for(int t = 1 ; t <= n ; ++t) dis[t] = INF ;
    for(int t = 1 ; t <= m ; ++t){
        int u, v, w ; cin >> u >> v >> w ;
        add(u, v, w) ; //add(v, u, w) ;
    }

    vector <bool> vis(n + 1) ;
    priority_queue<pii, vector<pii>, greater<pii>> pq ;
    pq.push({0, s}) ;
    dis[s] = 0 ;
    //pq of (d, u)
    while(!pq.empty()){
        auto [d, u] = pq.top() ;
        pq.pop() ;
        if(d != dis[u]) continue ;
        if(vis[u]) continue ;
        vis[u] = true ;

        for(int i = head[u] ; i ; i = edge[i].next){
            int v = edge[i].to ;
            int w = edge[i].wt ;

            if(w + dis[u] < dis[v]){
                dis[v] = w + dis[u] ;
                pq.push({dis[v], v}) ;
            }
        }
    }

    for(int t = 1 ; t <= n ; ++t) {
        if(dis[t] == INF) cout << (1 << 31) - 1 ;
        else cout << dis[t] << ' ' ;
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】P4779 【模板】单源最短路径（标准版）
 * 题目链接：https://www.luogu.com.cn/problem/P4779
 * 标签：难度 洛谷 普及+/提高 | 最短路, Dijkstra 堆优化
 *
 * 关键思路：堆优化 Dijkstra 模板：小根堆存 (dis, u)，每次弹出时用 if (d != dis[u]) continue 跳过过期状态；松弛成功就入堆。核心是"出堆即定型"（非负权）。
 * ###################################################################### */

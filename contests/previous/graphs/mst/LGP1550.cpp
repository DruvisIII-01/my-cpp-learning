#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 2000 ;
int e[MAXN][MAXN] ;
struct Node{
    int u, v, w ;
}edge[MAXN * MAXN] ;
auto cmp_w = [](const auto& x, const auto& y){
    return x.w < y.w ;
} ;
int fa[MAXN] ;

int find_set(int x){
    if(x == fa[x]) return x ;
    fa[x] = find_set(fa[x]) ;
    return fa[x] ;
}
signed main() {
    int n ; cin >> n ;
    for(int t = 1 ; t <= n ; t++) {
        int w ; cin >> w ; 
        e[n + 1][t] = w ;
        e[t][n + 1] = w ;
    }
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; ++j){
            int w ; cin >> w ;
            e[i][j] = e[j][i] = w ;
        }
    }
    int cnt = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i + 1 ; j <= n + 1 ; j++){
            if(!e[i][j]) continue ;
            cnt++ ;
            edge[cnt].u = i ;
            edge[cnt].v = j ;
            edge[cnt].w = e[i][j] ;
        }
    }
    sort(edge + 1, edge + cnt + 1, cmp_w) ;

    int T = 0, ans = 0 ;
    for(int t = 1 ; t <= n + 1 ; ++t) fa[t] = t ;
    for(int t = 1 ; t <= cnt ; ++t){
        int x = edge[t].u, y = edge[t].v, w = edge[t].w ;
        if(find_set(x) == find_set(y)) continue ;
        ans += w ; T++ ; fa[find_set(x)] = fa[find_set(y)] ;
        if(T == n) break ;
    }
    if(T == n) cout << ans ;
    else cout << "OrZ" ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】P1550 [USACO08OCT] Watering Hole G
 * 题目链接：https://www.luogu.com.cn/problem/P1550
 * 标签：难度 洛谷 普及+/提高 | 最小生成树, Kruskal
 *
 * 关键思路：新建一个虚拟点 n+1 表示"打井"，在第 i 个点打井的代价就是虚拟点与 i 之间的边权 w[i]。于是问题变成在 n+1 个点上求最小生成树：Kruskal 排序 + 并查集，凑满 n 条边即可（输出 OrZ 表示不连通）。
 * ###################################################################### */

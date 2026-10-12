#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 224524 ;
const int MAXM = 224524 ;
struct Node{
    int u, v, w ;
}edge[MAXN] ;
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
    int n, m ; cin >> n >> m ; 
    for(int t = 1 ; t <= m ; ++t)
    cin >> edge[t].u >> edge[t].v >> edge[t].w ;
    sort(edge + 1, edge + 1 + m, cmp_w) ;

    //for(int t = 1 ; t <= m ; ++t) cout << edge[t].w << endl ;
    for(int t = 1 ; t <= n ; ++t) fa[t] = t ; 
    int cnt = 0, ans = 0 ;
    for(int t = 1 ; t <= m ; ++t){
        int x = edge[t].u, y = edge[t].v, w = edge[t].w ;
        if(find_set(x) == find_set(y)) continue ;
        cnt++ ; ans += w ; fa[find_set(x)] = find_set(y) ;
        if(cnt == n - 1) break ;
    }  
    if(cnt == n - 1) cout << ans ;
    else cout << "orz" ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】P3366 【模板】最小生成树
 * 题目链接：https://www.luogu.com.cn/problem/P3366
 * 标签：难度 洛谷 普及+/提高 | 最小生成树, Kruskal
 *
 * 关键思路：Kruskal 模板：按边权排序，用并查集判断两端是否已连通，不连通就选这条边；选够 n−1 条即为答案，否则图不连通（输出 orz）。注意边数组按 m 开。
 * ###################################################################### */

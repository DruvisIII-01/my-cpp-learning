#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 6666 ;
struct Node{
    int to ;
    int next ;
}edge[MAXN] ;
int head[MAXN] ; int num = 0 ;
void add(int u, int v){
    num++ ;
    edge[num].to = v ;
    edge[num].next = head[u] ;
    head[u] = num ;
}
int r[MAXN] ;
struct info{
    int yes ;
    int no ; 
} ;
//int dp[MAXN][2] ;
struct info dancing(int x){
    if(!head[x]) {
        //dp[x][1] = r[x] ;
        //dp[x][0] = 0 ;
        return {r[x], 0} ;
    }
    int Y = r[x] ;
    int N = 0 ;
    for(int i = head[x] ; i ; i = edge[i].next){
        int son = edge[i].to ;
        struct info S = dancing(son) ;
        Y += S.no ;
        N += max(S.yes, S.no) ; 
    }
    return {Y, N} ;
}

signed main() {
    int n ; cin >> n ;
    for(int i = 1 ; i <= n ; ++i) cin >> r[i] ;

    vector<bool> is_root(n + 1, true) ;
    for(int i = 1 ; i <= n - 1 ; ++i) {
        int l, k ; cin >> l >> k ; 
        add(k, l) ;
        is_root[l] = false ;
    }

    int root = -1 ;
    for(int i = 1 ; i <= n ; ++i){
        if(is_root[i]) {
            root = i ;
            break ;
        }
    }//cout << root << endl ;

    struct info M = dancing(root) ;
    cout << max(M.yes, M.no) ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】P1352 没有上司的舞会
 * 题目链接：https://www.luogu.com.cn/problem/P1352
 * 标签：难度 洛谷 普及+/提高 | 树形dp
 *
 * 关键思路：经典树形 DP：dp[x][1] = r[x] + Σ dp[son][0]，dp[x][0] = Σ max(dp[son][0], dp[son][1])。先由入边找出唯一的根（题面保证是树、无环），再从根 DFS。这里用返回结构体 {yes, no} 的形式实现。
 * ###################################################################### */

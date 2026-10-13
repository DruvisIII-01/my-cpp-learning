#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 224524 ;
int n ; int a[MAXN] ; int ans ;
map<int, bool> is_square ;

struct info{
    int sum1, sum2, sum3 ;
    //将，以所有子节点为根的子树的节点数，存入一个数组
    //sum1表示所有元素的和etc
} ;
struct info dfs(int u, int fa, vector<vector<int>>& adj){
    int s1 = 0 ; int s2 = 0 ; int s3 = 0 ;
    int sonNum = 0 ;
    for(int v : adj[u]){
        if(v == fa) continue ;
        sonNum++ ;
        struct info IS = dfs(v, u, adj) ;
        s1 += (1 + IS.sum1) ;
        s2 += (1 + IS.sum1) * (1 + IS.sum1) ;
        s3 += (1 + IS.sum1) * (1 + IS.sum1) * (1 + IS.sum1) ;
    }
    int tot2 = s2 + (n - 1 - s1) * (n - 1 - s1) ;
    int tot3 = s3 + (n - 1 - s1) * (n - 1 - s1) * (n - 1 - s1) ;
    int c32 = (n - 1) * tot2 - tot3 ;
    if(is_square[a[u]]){
        if(fa) sonNum++ ;//不是根
        if(sonNum >= 2) ans += (((n - 1) * (n - 1) - tot2) / 2) ;
        if(sonNum >= 3) ans += ((n - 1) * (n - 1) * (n - 1) - 3 * c32 - tot3) / 6 ;
    }return {s1, s2, s3} ;
}

void solve(){
    cin >> n ; ans = 0 ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    vector<vector<int>> adj(n + 1) ;
    for(int t = 1 ; t <= n - 1 ; ++t) {
        int u, v ; cin >> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    struct info iff = dfs(1, 0, adj) ;
    cout << ans ;
}

signed main() {
    for(int t = 0 ; t <= 1111 ; t++) is_square[t * t] = true ;
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Fair and Square
 * 题目链接：https://codeforces.com/problemset/problem/2241/E
 * 标签：难度 1600 | combinatorics, dp, graphs, math, number theory, trees
 *
 * 关键思路：树上统计"三个有根子树大小凑成平方数"等组合。dfs(u) 返回以 u 为根的子树的 Σsize、Σsize²、Σsize³，配合"父方向那棵子树"的大小 (n−1−s1) 算出总的二阶/三阶和，再用组合数把节点值（与"所取子树大小之和为完全平方数"相关）分类计数。核心是"用幂和算组合量"避免 O(n²) 枚举。
 * ###################################################################### */

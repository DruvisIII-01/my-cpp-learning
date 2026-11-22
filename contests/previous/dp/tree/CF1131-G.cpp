#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 224524, Mod = 998244353 ;
int depth[MAXN], K[MAXN] ;
bool total, decided[MAXN] ;
string x, y ;

int q_pow(int a, int x){
    int res = 1, tmp_x = x, tmp_a = a ; 
    while(tmp_x){
        if(tmp_x & 1) res = res * tmp_a % Mod ; 
        tmp_x >>= 1 ;
        tmp_a = tmp_a * tmp_a % Mod ;
    }return res ; 
}

void dfs(int cur, int fa, int carry, vector<vector<int>>& adj){
    //cout << cur << ' ' << fa << ' ' << carry ; 
    depth[cur] = depth[fa] + 1 ;
    int D = depth[cur] ;

    if(!decided[D]) {
        K[D] = (x[cur] - '0') ^ (y[cur] - '0') ^ carry ;
        decided[D] = true ;
    }else if(K[D] != ((x[cur] - '0') ^ (y[cur] - '0') ^ carry)) total = false ;

    int next_carry = (((x[cur] - '0') + K[D] + carry) >= (int)2) ;
    //cout << ' ' << (x[cur] - '0') + (y[cur] - '0') + carry << ' ' << next_carry << endl ;
    for(int son : adj[cur]) if(son != fa) dfs(son, cur, next_carry, adj) ;
}

void solve(){
    //input
    int n ; cin >> n ; 
    vector<vector<int>> adj(n + 1) ;
    for(int t = 1 ; t <= n - 1 ; ++t) {
        int u, v ; cin >> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }cin >> x >> y ; x = '*' + x ; y = '*' + y ;
    
    //process
    total = true ; dfs(1, 0, 0, adj) ;
    if(!total) cout << "-1" ; 
    else{
        int ans = 0, mxD = -1 ;
        for(int t = 1 ; t <= n ; ++t) mxD = max(depth[t], mxD) ;
        //cout << mxD << endl ;
        for(int t = 1 ; t <= mxD ; ++t)
        if(K[t]) ans = (ans + q_pow(2, t - 1)) % Mod ;
        //cout << K[t] << ' ' ;
        cout << ans ; 
    }

    //clear
    for(int t = 1 ; t <= n ; ++t) {
        depth[t] = 0 ; 
        K[t] = 0 ;
        decided[t] = false ;
    }
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
 * 【题面与关键思路】0s and 1s
 * 题目链接：https://codeforces.com/problemset/problem/2278/G
 * 标签：难度 2278G（新场次，暂无 rating） | bitmasks, dfs, dp, hashing, number theory, trees
 *
 * 关键思路：树上 DFS 记录每个深度上的"进位/异或"约束：同一深度的所有节点必须满足 K[depth] 一致，冲突则无解；最后用快速幂把每层的自由选择数乘起来取模。
 * ################################################################## */

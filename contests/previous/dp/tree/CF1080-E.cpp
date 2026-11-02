#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 300011 ;
const int mod = 1000000007 ;
int dp[MAXN], mv[MAXN], n, son[MAXN][2] ;

int dfs1(int x){
    if(son[x][1] == 0 && son[x][0] == 0) dp[x] = 0 ;
    else dp[x] = dfs1(son[x][1]) + dfs1(son[x][0]) + 4 ;
    dp[x] %= mod ;
    return dp[x] ;
}

void dfs2(int x, int fa){
    mv[x] = mv[fa] + 1 + dp[x] ;
    mv[x] %= mod ;
    if(son[x][1] == 0 && son[x][0] == 0) return ;
    dfs2(son[x][1], x) ; 
    dfs2(son[x][0], x) ;
}

void solve(){
    cin >> n ;
    for(int t = 1 ; t <= n ; ++t) cin >> son[t][0] >> son[t][1] ;
    
    int res1 = dfs1(1) ;
    //dp
    dfs2(1, 0) ; 
    //mv

    for(int t = 1 ; t <= n ; ++t) cout << mv[t] << ' ' ;
    for(int t = 1 ; t <= n ; ++t){
        dp[t] = 0 ;
        mv[t] = 0 ;
        son[t][1] = son[t][0] = 0 ;
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
 * 【题面与关键思路】Idiot First Search
 * 题目链接：https://codeforces.com/problemset/problem/2195/E
 * 标签：难度 1500 | dfs and similar, dp, trees
 *
 * 关键思路：树上 DP：`dp[x]` = 子树内所有叶子到 x 的深度和（`dp[x] = dp[l]+dp[r]+4`），再 dfs2 做换根求出每个点为根时的总深度和。
 * ################################################################## */

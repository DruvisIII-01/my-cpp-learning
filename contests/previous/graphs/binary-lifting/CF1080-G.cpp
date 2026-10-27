#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 333333 ;
const int Log = 20 ;
const int inf = (int)1e18 ;
int dp[MAXN], fa[MAXN], son[MAXN][2] ;
int up[MAXN][Log], cost[MAXN][Log] ;
int dfn[MAXN], rr[MAXN * 2] ;
int num = 1 ;

int dfs1(int x){
    if(son[x][1] == 0 && son[x][0] == 0) dp[x] = 0 ;
    else dp[x] = dfs1(son[x][1]) + dfs1(son[x][0]) + 4 ;
    //dp[x] %= mod ;
    return dp[x] ;
}

void dfs2(int x){
    dfn[x] = num ;
    rr[num] = x ;
    num++ ;
    if(!son[x][0]) return ;
    
    dfs2(son[x][0]) ;
    rr[num] = x ; 
    num++ ;
    dfs2(son[x][1]) ;
    rr[num] = x ; 
    num++ ;
}

int dfs3(int v, int k){
    if(k <= dp[v]) return rr[dfn[v] + k] ;
    k -= (dp[v] + 1) ;
    int cur = fa[v] ;
    for(int L = Log - 1 ; L >= 0 ; L--){
        if(up[cur][L] != 0 && k >= cost[cur][L]){
            k -= cost[cur][L] ;
            cur = up[cur][L] ;
        }
    }
    int res2 = rr[dfn[cur] + k] ;
    return res2 ;
}

void solve(){
    int n, q ; cin >> n >> q ;
    for(int t = 1 ; t <= n ; ++t){
        cin >> son[t][0] >> son[t][1] ;
        if(son[t][0] != 0 && son[t][1] != 0){
            fa[son[t][0]] = t ;
            fa[son[t][1]] = t ;
        }
    } 
    
    int res1 = dfs1(1) ;
    num = 1 ; dfs2(1) ;
    for(int t = 1 ; t <= n ; ++t) up[t][0] = fa[t] ;
    for(int t = 1 ; t <= n ; ++t) cost[t][0] = dp[t] + 1 ;
    for(int l = 0 ; l < Log ; ++l) cost[0][l] = inf ;
    for(int l = 1 ; l < Log ; ++l){
        for(int t = 1 ; t <= n ; ++t){
            int mid = up[t][l - 1] ;
            if(!mid) {
                cost[t][l] = inf ;
                up[t][l] = 0 ;
            }
            else {
                cost[t][l] = cost[t][l - 1] + cost[mid][l - 1] ;
                up[t][l] = up[mid][l - 1] ;
            }
        }
    }

    for(int TTT = 1 ; TTT <= q ; ++TTT){
        int v, k ; cin >> v >> k ;
        cout << dfs3(v, k) << ' ' ;
    }
    for(int t = 1 ; t <= n ; ++t){
        son[t][0] = son[t][1] = 0 ;
        fa[t] = 0 ;
        dp[t] = 0 ; 
        dfn[t] = 0 ;
        rr[t] = 0 ;
        for(int L = 0 ; L < Log ; ++L){
            up[t][L] = 0 ;
            cost[t][L] = 0 ;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

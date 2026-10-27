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
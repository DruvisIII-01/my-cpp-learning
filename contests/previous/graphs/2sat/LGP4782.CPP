#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 1e6 + 222 ;
const int MAXM = 1e6 + 222 ;

struct Node{
    int to, next ;
}e[MAXM << 1] ;
int num = 0 ;//边数
int head[MAXN << 1] ;//顶点的第一条边
void add(int u, int v){
    num++ ;
    e[num].to = v ;
    e[num].next = head[u] ;
    head[u] = num ;
}

int DFN[MAXN << 1] ;
int low[MAXN << 1] ;
int dfn = 0 ;
int stk[MAXN << 1] ; int len = 0 ;//栈指针
bool ins[MAXN << 1] ;
int scc[MAXN << 1] ; int cnt = 0 ;//分量数
void dfs(int x){
    dfn++ ;
    DFN[x] = dfn ;
    low[x] = dfn ;

    len++ ;
    ins[x] = true ;
    stk[len] = x ;

    for(int i = head[x] ; i ; i = e[i].next){
        int y = e[i].to ;
        if(!DFN[y]){
            dfs(y) ;
            low[x] = min(low[y], low[x]) ;
        }else if(ins[y]) low[x] = min(low[x], DFN[y]);
    }

    if(DFN[x] == low[x]){
        cnt++ ;
        while(stk[len] != x){
            scc[stk[len]] = cnt ;
            ins[stk[len]] = false ;
            len-- ;
        }scc[x] = cnt ;
        ins[x] = false ;
        len-- ;
    }
}

bool SAT2(int n){
    for(int i = 1 ; i <= n ; ++i) if(scc[i] == scc[i + n]) return false ;
    return true ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m ; cin >> n >> m ;
    for(int t = 1 ; t <= m ; ++t){
        int u, v, a, b ; cin >> u >> a >> v >> b ;
        add(u + n * (a ^ 1), v + n * b);
        add(v + n * (b ^ 1), u + n * a);
    }
    for(int i = 1 ; i <= 2 * n ; ++i) if(!DFN[i]) dfs(i) ;
    // for(int i = 1 ; i <= 2 * n ; ++i) cout << scc[i] << ' ' ;
    // cout << '\n' ;
    if(SAT2(n)){
        cout << "POSSIBLE" << '\n' ;
        for(int i = 1 ; i <= n ; ++i){
            if(scc[i + n] > scc[i]) cout << '0' << ' ' ;
            else cout << '1' << ' ' ;
        }
    }else cout << "IMPOSSIBLE" << '\n' ;
    
    return 0;
}
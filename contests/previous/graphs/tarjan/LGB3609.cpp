#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 10000 + 222 ;
const int MAXM = 100000 + 2222 ;

struct node{int to, next ;}e[MAXM << 1] ;
int head[MAXN] ;
int num = 1 ;//边的序数

int DFN[MAXN] ; int dfn = 1 ;//dfs序数
int low[MAXN] ;
int stk[MAXN] ; int len = 0 ;//栈指针
bool instk[MAXN] ;
vector<vector<int>> scc(MAXN + 1) ; int cnt = 0 ;//强连通分量数
int belong[MAXN] ; bool out[MAXN] ; 

void add(int u, int v){
    e[num].to = v ;
    e[num].next = head[u] ;
    head[u] = num ;
    num++ ;
}
void dfs(int x){
    DFN[x] = dfn ; 
    low[x] = dfn ;
    dfn++ ;
    len++ ;
    stk[len] = x ;
    instk[x] = true ;
    for(int i = head[x] ; i != -1 ; i = e[i].next){
        int y = e[i].to ;
        if(!DFN[y]){
            dfs(y) ;
            low[x] = min(low[x], low[y]) ;
        }else if(instk[y]) low[x] = min(low[x], low[y]) ;
    }
    if(low[x] == DFN[x]){
        cnt++ ;belong[x] = cnt ;
        scc[cnt].push_back(x) ;
        instk[x] = false ;
        while(x != stk[len]){
            scc[cnt].push_back(stk[len]) ;
            instk[stk[len]] = false ;
            belong[stk[len]] = cnt ;
            len-- ;
        }len-- ;
    }
}

void init(){
    memset(head, -1, sizeof(head)) ;
    memset(instk, 0, sizeof(instk)) ;
    memset(stk, 0, sizeof(stk)) ;
    memset(DFN, 0, sizeof(DFN)) ;
}
signed main() {
    init() ;
    int n, m ; cin >> n >> m ;
    for(int t = 1 ; t <= m ; ++t){
        int x, y ; cin >> x >> y ;
        add(x, y) ;
    }
    for(int i = 1 ; i <= n ; i++) if(!DFN[i])dfs(i) ;
    for(int i = 1 ; i <= cnt ; i++)
    sort(scc[i].begin(), scc[i].end()) ;
    cout << cnt << endl ;
    for(int i = 1 ; i <= n ; i++){
        if(out[belong[i]]) continue ;
        out[belong[i]] = true ;
        for(int u : scc[belong[i]]) cout << u << ' ' ;
        cout << endl ;
    }
    return 0;
}
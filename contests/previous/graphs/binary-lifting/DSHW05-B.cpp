#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 114514 ;
const int LIMIT = 20 ;
struct Node{
    int to, next ;
}edge[MAXN] ;
int head[MAXN] ; int num = 0 ;
void add(int u, int v){
    num++ ;
    edge[num].to = v ;
    edge[num].next = head[u] ;
    head[u] = num ;
}

int deep[MAXN], st[MAXN][LIMIT] ;
void dfs(int x, int Fa, int val){
    deep[x] = val ;
    st[x][0] = Fa ;
    for(int i = head[x] ; i ; i = edge[i].next){
        int nb = edge[i].to ;
        if(nb == Fa) continue ;
        dfs(nb, x, val + 1) ;
    } 
}

signed main() {
    int n ; cin >> n ; 
    for(int t = 0 ; t < n ; ++t){
        int N ; cin >> N ; 
        for(int i = 0 ; i < N ; ++i){
            int v ; cin >> v ;
            add(t, v) ;
        }
    }dfs(0, -1, 0) ;st[0][0] = 0 ;
    // for(int t = 0 ; t < n ; ++t) cout << deep[t] << ' ' ;
    // cout << endl ;

    for(int d = 1 ; d < LIMIT ; ++d){
        for(int t = 0 ; t < n ; ++t){
            int mid = st[t][d - 1] ;
            st[t][d] = st[mid][d - 1] ;
        }
    }
    //for(int t = 0 ; t < n ; ++t) cout << st[t][0] << ' ' ;
    //cout << endl ;

    int q ; cin >> q ; 
    for(int QWQ = 1 ; QWQ <= q ; ++QWQ){
        int u, v ; cin >> u >> v ;
        //cout << deep[u] << ' ' << deep[v] << ' ' ;
        if(u == v) {
            cout << u << endl ;
            continue ;
        }
        else if(deep[u] < deep[v]) swap(u, v) ;
        //cout << u << ' ' << v << ' ' ;
        
        if(deep[u] > deep[v]){
            int cur = u ; 
            for(int D = LIMIT - 1 ; D >= 0 ; D--)
            if(deep[st[cur][D]] > deep[v]) cur = st[cur][D] ;
            u = st[cur][0] ;
        } 
        //cout << u << ' ' << v << ' ' ;

        if(u == v) {
            cout << u << endl ;
            continue ;
        }
        for(int D = LIMIT - 1 ; D >= 0 ; D--){
            if(st[u][D] != st[v][D]){
                u = st[u][D] ;
                v = st[v][D] ;
            }
        }cout << st[u][0] << endl ;
    }
    return 0;
}
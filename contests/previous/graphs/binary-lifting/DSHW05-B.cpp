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

/* ##################################################################
 * 【题面与关键思路】DSHW05-B 树上倍增求 LCA
 * 来源：数据结构课程作业（非竞赛题，无官方难度/标签）
 * 标签：课程作业 | 倍增, LCA
 *
 * 关键思路：先 DFS 预处理每个点的深度与 st[x][0]（父亲），再倍增出 st[x][k]；查询时把较深的点跳到同深度，然后两点一起往上跳，直到父节点相同。
 * ################################################################## */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 2e5 + 123, MAXM = 2e5 + 123 ;
struct Edge {
    int to, next ; 
} edges[MAXM] ;

int n, m ; 
int cnt ;
int tot ;
int id ;
int head[MAXN] ;
int in[MAXN] ;
int und[MAXM][2] ;
int topoid[MAXN] ;
queue <int> que ;

void init(){
    cnt = 0 ;
    tot = 0 ;
    id = 0 ;
    memset(head, 0, sizeof(head)) ;
    memset(in, 0, sizeof(in)) ;
    //memset(und, 0x3f, sizeof(und)) ;
    memset(topoid, -1, sizeof(topoid)) ;
    while(!que.empty()) que.pop() ;
}

void addEdge(int u, int v){
    //add an edge pointing from u to v
    cnt++ ;
    edges[cnt].to = v ;
    edges[cnt].next = head[u] ;
    head[u] = cnt ;
}

bool toposort(){
    for(int i = 1 ; i <= n ; i++) {
        if(!in[i]) que.push(i) ;
    }
    while(!que.empty()){
        int tp = que.front() ; que.pop() ;
        id++ ; topoid[tp] = id ;
        int hd = head[tp] ;
        while(hd != 0){
            int nb = edges[hd].to ;
            in[nb]-- ;
            if(!in[nb]) que.push(nb) ;
            hd = edges[hd].next ;
        }
    }
    if(n == id) return true ;
    return false ;
}

signed main() {
    ios::sync_with_stdio(false);  // ← 关闭同步
    cin.tie(0);                   // ← 解除cin和cout的绑定
    cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        init() ;
        cin >> n >> m ;
        while(m--){
            int type, V1, V2 ; cin >> type >> V1 >> V2 ;
            if(type) {
                addEdge(V1, V2) ;
                in[V2]++ ;
            }else{
                tot++ ;
                und[tot][0] = V1 ;
                und[tot][1] = V2 ;
            }
        }if(!toposort()) cout << "NO" << endl ;
        else{
            cout << "YES" << endl ;
            for(int i = 1 ; i <= tot ; i++){
                int x = und[i][0], y = und[i][1] ;
                if(topoid[x] < topoid[y]) cout << x << ' ' << y << endl ; 
                else cout << y << ' ' << x << endl ;
            }
            for(int i = 1 ; i <= n ; i++){
                for(int j = head[i] ; j ; j = edges[j].next)
                cout << i << ' ' << edges[j].to << endl ;
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 2e5 + 123 ;

struct Edge{
    int to ; 
    int next ;
    int val ;
} edges[MAXN << 1] ;
int T, n, s, cnt, cur, ans ;
int head[MAXN], W[MAXN], sum[MAXN], nums[MAXN] ;
struct P{
    int id ; 
    int val ;
} ; 
auto cmp = [](const auto& P1, const auto& P2){
    return (P1.val - P1.val / 2) * nums[P1.id] < 
    (P2.val - P2.val / 2) * nums[P2.id] ;
} ; priority_queue <P, vector<P>, decltype(cmp)> pq(cmp) ;

inline void init(){
    cnt = 0 ; 
    cur = 0 ;
    ans = 0 ;
    for(int i = 1; i <= n; i++){  // ← 只清空 n 个元素
        head[i] = 0;
        W[i] = 0;
        sum[i] = 0;
        nums[i] = 0;
    }
    while(!pq.empty()) pq.pop() ;
}

inline void addEdge(int u, int v, int w){
    cnt++ ;
    edges[cnt].to = v ;
    edges[cnt].next = head[u] ;
    edges[cnt].val = w ;
    head[u] = cnt ;
}

int dfs(int now, int pre){
    int leafs = 0 ; 
    bool has_succ = false ;
    for(int i = head[now] ; i ; i = edges[i].next){
        int nb = edges[i].to ; 
        if(nb == pre) continue ;
        has_succ = true ;
        leafs += dfs(nb, now) ;
        W[nb] = edges[i].val ;
        sum[nb] = edges[i].val * nums[nb] ;
    }
    if(!has_succ) return nums[now] = 1 ;
    else return nums[now] = leafs ;
}

signed main() {
    ios::sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;
    cin >> T ;
    while(T--){
        cin >> n >> s ;
        init() ;
        for(int t = 1 ; t <= n - 1 ; t++){
            int V1, V2, W0 ; cin >> V1 >> V2 >> W0 ;
            addEdge(V2, V1, W0) ; addEdge(V1, V2, W0) ;
        }
        dfs(1, 0) ;
        for(int t = 2 ; t <= n ; t++){
            P to_add = {t, W[t]} ;
            pq.push(to_add) ;
            cur += sum[t] ;
        }
        while(cur > s){
            ans++ ;
            P tp = pq.top() ; pq.pop() ;
            int X = tp.id, Y = tp.val ;
            cur -= (Y * nums[X] - Y / 2 * nums[X]) ;
            P nw = {X, Y / 2} ;
            pq.push(nw) ;
        }
        cout << ans << '\n' ;
    }
    return 0;
}
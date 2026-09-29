#include <bits/stdc++.h>
using namespace std ;

#define int long long
int n, m ; 

vector<int> build(int u, int v,
vector<int>& parent, vector<int>& depth){
    int u0 = u, v0 = v ;
    while(depth[u] > depth[v]) u = parent[u] ;
    while(depth[v] > depth[u]) v = parent[v] ;
    while(u != v){
        u = parent[u] ;
        v = parent[v] ;
    }int lca = u ;

    vector<int> res ;
    vector<int> tmp ;
    while(u0 != lca){
        res.push_back(u0) ;
        u0 = parent[u0] ;
    }res.push_back(lca) ;
    while(v0 != lca){
        tmp.push_back(v0) ;
        v0 = parent[v0] ;
    }for(int i = tmp.size() - 1 ; i >= 0 ; i--){
        res.push_back(tmp[i]) ;
    }//res.push_back(u0) ;
    return res ;
}
vector<int> find(vector<vector<int>>& adj, vector<int>& parent,
vector<int>& depth, vector<int>& color){
    for(int i = 1 ; i <= n ; ++i){
        if(color[i] != 0) continue ;
        queue<int> que ;
        color[i] = 1 ;
        que.push(i) ;
        while(!que.empty()){
            int frt = que.front() ;
            for(int nb : adj[frt]){
                if(nb == parent[frt]) continue ;
                if(color[nb] == 0){
                    color[nb] = -color[frt] ;
                    parent[nb] = frt ;
                    depth[nb] = depth[frt] + 1 ;
                    que.push(nb) ;
                }else if(color[nb] == color[frt]){
                    return build(nb, frt, parent, depth) ;
                }
            }
            que.pop() ;
        }
    }
    vector<int>ans ;
    return ans ;
}

void solve(){
    cin >> n >> m ;
    vector<vector<int>> adj(n + 1, vector<int>()) ;
    for(int t = 1 ; t <= m ; ++t){
        int u, v ; cin >> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    vector<int> parent(n + 1, 0) ;
    vector<int> depth(n + 1, 0) ;
    vector<int> color(n + 1, 0) ;
    vector<int> res = find(adj, parent, depth, color) ;

    if(res.size() == 0) cout << "-1" ;
    else {
        cout << res.size() << endl ;
        for(int x : res) cout << x << ' ' ;
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
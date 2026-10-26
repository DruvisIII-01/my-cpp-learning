#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 114514 ;
const int MAXM = 224524 ;
int n, m, q ;
int fa[MAXN] ;
struct Node{
    int u, v, w ;
}edges[MAXM] ;
auto cmp = [](const auto& e1, const auto& e2){
    return e1.w < e2.w ;
} ;

void prt(vector<int>& a){
    if(a.empty()) {
        cout << "This array is empty!!!" << endl ; 
        return ;
    }
    cout << endl ; 
    for(int t = 0 ; t < a.size() ; ++t) cout << a[t] <<  ' ' ;
    cout << endl ;
}

int find_set(int x){
    //printf("Now, x = %d and fa = %d\n", x, fa[x]) ;
    if(x == fa[x]) return x ;
    fa[x] = find_set(fa[x]) ;
    return fa[x] ; 
}

void union_set(int x, int y){
    x = find_set(x) ;
    y = find_set(y) ;
    if(x == y) return ;
    fa[x] = y ;
}

void solve(){
    cin >> n >> m >> q ; for(int t = 1 ; t <= n ; ++t) fa[t] = t ;
    for(int t = 1 ; t <= m ; ++t) cin >> edges[t].u >> edges[t].v >> edges[t].w ;
    sort(edges + 1, edges + m + 1, cmp) ;

    vector<int> nmst ; int sum = 0 ;
    vector<int> mst ;
    for(int t = 1 ; t <= m ; ++t){
        int u = edges[t].u, v = edges[t].v, w = edges[t].w ;
        if(find_set(u) != find_set(v)){
            union_set(u, v) ;
            mst.push_back(w) ;
        }else {
            nmst.push_back(w) ;
            sum += w ;
        }
    }

    int V = -1 ;
    for(int t = 1 ; t <= n ; ++t) V += (fa[t] == t) ;
    int sz = mst.size() ; //cout << V << ' ' << sz << endl ; 
    vector<int> suf(sz + 1) ;
    for(int t = sz - 1 ; t >= 0 ; t--) suf[t] = suf[t + 1] + mst[t] ;
    // prt(mst) ;
    // prt(suf) ;
    // prt(nmst) ;
    
    for(int TTT = 1 ; TTT <= q ; TTT++){
        int x ; cin >> x ;
        int basic = sum - V * (V + 1) * x / 2 ;
        if(!sz || (V + 1) * x > mst[sz - 1]) cout << basic << ' ' ;
        else {
            int left = 1, right = sz + 1 ; 
            while(left + 1 != right){
                int mid = (left + right) >> 1 ;
                if(mst[sz - mid] >= (V + mid) * x) left = mid ;
                else right = mid ;
            }
            int earn = suf[sz - left], cost = (left + 1) * left / 2 + left * V ;
            cout << earn + basic - cost * x << ' ' ;
        }
    }

    for(int t = 1 ; t <= m ; ++t) edges[t].u = edges[t].v = edges[t].w = 0 ;
    for(int t = 1 ; t <= n ; ++t) fa[t] = 0 ; 
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
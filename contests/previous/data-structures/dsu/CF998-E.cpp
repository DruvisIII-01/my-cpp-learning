#include <bits/stdc++.h>
using namespace std ;

#define int long long

int find_set(int x, vector<int>& fa){
    if(x == fa[x]) return x ;
    fa[x] = find_set(fa[x], fa) ;
    return fa[x] ;
}

void union_set(int x, int y, vector<int>& fa){
    x = find_set(x, fa) ;
    y = find_set(y, fa) ;
    if(x == y) return ;
    else if(x < y) swap(x, y) ; 
    fa[x] = y ;
}

void solve(){
    int n, m1, m2 ; cin >> n >> m1 >> m2 ;
    vector<int> fa(n + 1) ; for(int t = 1 ; t <= n ; ++t) fa[t] = t ;
    vector<int> ga(n + 1) ; for(int t = 1 ; t <= n ; ++t) ga[t] = t ;   
    vector<vector<int>> Ef(m1 + 1, vector<int>(2)) ;

    for(int t = 1 ; t <= m1 ; ++t) {
        int u, v ; cin >> u >> v ;
        Ef[t][0] = u ; 
        Ef[t][1] = v ;
    }for(int t = 1 ; t <= m2 ; ++t) {
        int u, v ; cin >> u >> v ;
        union_set(u, v, ga) ;
    }

    int del = 0 ;
    for(int t = 1 ; t <= m1 ; ++t) {
        int u = Ef[t][0], v = Ef[t][1] ;
        if(find_set(u, ga) != find_set(v, ga)) del++ ;
        else union_set(u, v, fa) ;
    }

    int cnt_f = 0 ; for(int t = 1 ; t <= n ; ++t) cnt_f += (fa[t] == t) ;
    int cnt_g = 0 ; for(int t = 1 ; t <= n ; ++t) cnt_g += (ga[t] == t) ;
    int add = cnt_f - cnt_g ; cout << del + add ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
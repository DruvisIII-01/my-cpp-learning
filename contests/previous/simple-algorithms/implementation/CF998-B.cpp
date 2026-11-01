#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ;
    vector<vector<int>> a(n + 1, vector<int>(m + 1)) ;
    vector<int> mi(n + 1) ;
    vector<int> order(n * m + 1) ;
    for(int t = 1 ; t <= n ; ++t){
        mi[t] = m * n * 2 ;
        for(int i = 1 ; i <= m ; ++i){
            cin >> a[t][i] ;
            mi[t] = min(mi[t], a[t][i]) ;
        }order[mi[t]] = t ;
    }//for(int t = 1 ; t <= n ; ++t) cout << mi[t] << ' ' ;

    sort(mi.begin() + 1, mi.end()) ;
    bool ans = true ;
    for(int t = 1 ; t <= n ; ++t) {
        int tar = order[mi[t]] ;
        for(int i = 1 ; i <= m ; ++i){
            if((a[tar][i] - mi[t]) % n != 0
              || a[tar][i] > mi[t] + (m - 1) * n){
                ans = false ;
                break ;
            }
        }if(!ans) break ;
    }if(!ans) cout << "-1" ;
    else for(int t = 1 ; t <= n ; ++t) cout << order[mi[t]] << ' ' ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
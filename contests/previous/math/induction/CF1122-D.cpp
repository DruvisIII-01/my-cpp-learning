#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
    vector<int> b(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) b[i] = (a[i] - i) ;
    
    map<int, bool> vis ;
    vector<int> d ;
    for(int i = 1 ; i <= n ; ++i){
        if(!vis[b[i]]){
            vis[b[i]] = 1 ;
            d.push_back(b[i]) ;
        }
    }int sz = d.size() ;
    sort(d.begin(), d.end()) ;
    // for(int i = 0 ; i < sz ; ++i) cout << d[i] << ' ' ;
    // cout << endl ;
    
    for(int i = 0 ; i < sz ; ++i) d[i] -= i ;
    // for(int i = 0 ; i < sz ; ++i) cout << d[i] << ' ' ;
    // cout << endl ;
    int mx = 1 ;
    int cur = 1 ;
    for(int i = 1 ; i < sz ; ++i){
        if(d[i] == d[i - 1]){
            cur++ ;
            if(i == sz - 1) mx = max(cur, mx) ;
        }else{
            mx = max(cur, mx) ;
            cur = 1 ;
        }
    }
    cout << mx ;
} 

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
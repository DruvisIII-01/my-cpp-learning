#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1), b(n + 1) ;
    map<int, int> id ; 
    for(int t = 1 ; t <= n ; ++t) cin >> b[t] ;
    for(int t = 1 ; t <= n ; ++t) id[t] = b[t] + n + 1 - t ;
    
    bool ans = true ;
    for(int t = 1 ; t <= n ; ++t) {
        if(id[t] > n || id[t] <= 0) {
            ans =  false ;
            break ;
        }if(!a[id[t]]) a[id[t]] = t ;
        else {
            ans = false ;
            break ; 
        }
    }if(ans) for(int t = 1 ; t <= n ; ++t) cout << a[t] << ' ' ;
    else cout << "-1" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
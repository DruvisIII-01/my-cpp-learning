#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    
    int mx1 = -1, mx2 = -1 ;
    int mx1i = -1, mx2i = -1 ;
    for(int t = 1 ; t <= n ; ++t){
        if(mx1 < a[t]){
            mx1 = a[t] ;
            mx1i = t ;
        }
    }
    for(int t = 1 ; t <= n ; ++t){
        if(mx1i == t) continue ;
        if(mx2 < a[t]){
            mx2 = a[t] ;
            mx2i = t ;
        }
    }
    for(int t = 1 ; t <= n ; ++t){
        if(t == mx1i) cout << a[t] - mx2 << ' ' ; 
        else cout << a[t] - mx1 << ' ' ; 
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
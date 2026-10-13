#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    int un = 1 ;
    vector<bool> vis(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) vis[a[t]] = true ;
    stack<int> stk ;
    for(int t = 1 ; t <= n ; ++t) if(!vis[t]) stk.push(t) ;
    for(int t = 1 ; t <= n ; ++t) vis[t] = false ;

    for(int t = 1 ; t <= n ; ++t){
        if(!vis[a[t]]){
            vis[a[t]] = true ;
            cout << a[t] << ' ' ;
        }else{
            int tp = stk.top() ;
            cout << tp << ' ' ;
            stk.pop() ;
        }
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
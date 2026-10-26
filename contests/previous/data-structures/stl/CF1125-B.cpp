#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ; s = '*' + s ;
    stack<int> scanned ; 
    vector<int> vis(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) {
        if(s[t] == '1') scanned.push(t) ;
        else if(s[t] == '2'){
            if(scanned.empty()) vis[t] = true ;
            else {
                int tp = scanned.top() ;
                scanned.pop() ;
                vis[tp] = true ;
            }
        }else vis[t] = true ;
    }

    int ans = 0 ;
    for(int t = 1 ; t <= n ; ++t) ans += !vis[t] ;
    cout << ans << endl ;
    for(int t = 1 ; t <= n ; ++t) 
    if(!vis[t]) cout << t << ' ' ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
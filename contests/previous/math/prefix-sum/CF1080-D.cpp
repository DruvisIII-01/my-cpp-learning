#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> f(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> f[t] ;
    
    int sum = (f[1] + f[n]) / (n - 1) ;
    vector<int> pre(n + 1) ;
    for(int t = 1 ; t < n ; ++t){
        int d = f[t + 1] - f[t] ;
        pre[t] = (sum + d) / 2 ;
    }

    pre[n] = sum ; 
    for(int t = 1 ; t <= n ; ++t) cout << pre[t] - pre[t - 1] << ' ' ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
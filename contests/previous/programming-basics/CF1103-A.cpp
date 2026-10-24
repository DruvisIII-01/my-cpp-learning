#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    int mx = -1, mi = 10 ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        mx = max(mx, a[t]) ;
        mi = min(mi, a[t]) ;
    }cout << mx - mi + 1 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
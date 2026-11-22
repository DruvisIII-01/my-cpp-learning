#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    sort(a.begin() + 1, a.end()) ;

    int ans1 = 0, ans2 = a[n] - a[1] ;
    for(int t = 2 ; t <= n ; ++t)
    ans1 += min((t - 1), (n - t + 1)) * (a[t] - a[t - 1]) ;       
    cout << ans1 << ' ' << ans2 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
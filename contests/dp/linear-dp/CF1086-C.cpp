#include <bits/stdc++.h>
using namespace std ;

// #define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> c(n+1), p(n+1) ;
    vector <double> r(n+1) ;
    for(int i = 1 ; i <= n ; i++)  {
        cin >> c[i] >> p[i] ;
        r[i] = 1.0-p[i]*1.0/100 ;
    }
    vector <double> dp(n+2) ;
    dp[n+1] = 0 ;
    for(int i = n ; i >= 1 ; i--) {
        dp[i] = max(1.0*c[i]+dp[i+1]*r[i], dp[i+1]) ;
    }
    printf("%.10lf", dp[1]) ;
    dp.clear();
    r.clear();
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
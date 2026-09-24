#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    vector<int> sum(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) sum[t] = sum[t - 1] + (a[t] < t) ;
    vector<int> dp(n + 1) ;
    for(int t = 3 ; t <= n ; ++t){
        if(a[t] >= t) dp[t] = dp[t - 1] ;
        else if(!a[t]) dp[t] = dp[t - 1] ;
        else dp[t] = dp[t - 1] + sum[a[t] - 1] ;
    }cout << dp[n] ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
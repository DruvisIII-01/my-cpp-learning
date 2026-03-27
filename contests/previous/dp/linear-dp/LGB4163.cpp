#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 224524 ;
 
#define int long long

int dp[MAXN][2] ;

signed main() {
    int n ; cin >> n ;
    vector <int> a(n+1, 0) ;
    vector <int> b(n+1, 0) ;
    //dp[i][0] means choose a[i] to be c[i] best
    //dp[i][1] means choose b[i] to be c[i] best
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    for(int i = 1 ; i <= n ; i++) cin >> b[i] ;
    dp[2][0] = min(abs(a[2]-a[1]), abs(a[2]-b[1])) ;
    dp[2][1] = min(abs(b[2]-a[1]), abs(b[2]-b[1])) ;
    for(int i = 3 ; i <= n ; i++){
        dp[i][0] = min(
            dp[i-1][0]+abs(a[i]-a[i-1]), dp[i-1][1]+abs(a[i]-b[i-1])
        );
        dp[i][1] = min(
            dp[i-1][0]+abs(b[i]-a[i-1]), dp[i-1][1]+abs(b[i]-b[i-1])  
        );
    }
    int ans = min(dp[n][1], dp[n][0]) ;
    cout << ans ;
    // for(int i = 2 ; i <= n ; i++){
    //     cout << dp[i][0] << ' ' << dp[i][1] << endl ;
    // }
    return 0;
}
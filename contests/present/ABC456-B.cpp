#include <bits/stdc++.h>
using namespace std ;

//#define int long long

const int mod = 998244353 ;

signed main() {
    string s ; cin >> s ;
    int n = s.size() ;
    vector <int> dp(n + 1) ;
    dp[1] = 1 ;
    int ans = dp[1] ;
    s = '*' + s ;
    for(int i = 2 ; i <= n ; i++){
        if(s[i] == s[i - 1]) dp[i] = 1 ;
        else dp[i] = dp[i - 1] + 1 ;
        dp[i] %= mod ;
        ans += dp[i] ;
        ans %= mod ;
    }
    cout << ans ;
    return 0;
}
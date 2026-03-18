#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 1e5 + 1223 ;
const int mod = 1e9 + 7 ;

signed main() {
    vector <int> dp(MAXN + 1) ;
    vector <int> zero(MAXN + 1) ;
    vector <int> one(MAXN + 1) ;
    zero[1] = 1, one[2] = 1 ;
    for(int i = 3 ; i <= MAXN ; i++){
        dp[i] = dp[i - 2] + dp[i - 1] + one[i - 2] * zero[i - 1] ;
        dp[i] %= mod ;
        zero[i] = zero[i - 2] + zero[i - 1] ;
        zero[i] %= mod ;
        one[i] = one[i - 2] + one[i - 1] ;
        one[i] %= mod ;
    }
    int T ;cin >> T ;
    while(T--) {
        int n ; cin >> n ;
        cout << dp[n] ;
        cout << endl ;
    }
    return 0;
}
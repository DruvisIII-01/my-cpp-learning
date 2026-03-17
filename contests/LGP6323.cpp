#include <bits/stdc++.h>
using namespace std ;

const int mod = 1e9 + 7 ;
const int MAXN = 1e3 + 111 ;
const int MAXC = 1e4 + 111 ;

//#define int long long

int dp[MAXC] ;
int pre[MAXC] ;

signed main() {
    int n, c ; cin >> n >> c ;
    dp[0] = 1 ;
    for(int i = 2 ; i <= n ; i++){
        pre[0] = dp[0] ;
        for(int j = 1 ; j <= c ; j++) {
            pre[j] = pre[j - 1] + dp[j] ;
            pre[j] %= mod ;
        }
        for(int j = 0 ; j <= c ; j++) {
            if(j - i >= 0) dp[j] = pre[j] - pre[j - i] + mod ;
            else dp[j] = pre[j] ;
            dp[j] %= mod ;
        }
    }
    cout << dp[c] ;
    return 0;
}
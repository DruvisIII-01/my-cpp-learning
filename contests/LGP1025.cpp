#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 222 ;
const int MAXK = 10 ;
int dp[MAXN][MAXK] ;

signed main() {
    int n, k ; cin >> n >> k ;
    for(int i = 1 ; i <= n ; i++){
        for(int x = 1 ; x <= k ; x++){
            if(i < x) dp[i][x] = 0 ;
            else if(i == x) dp[i][x] = 1 ;
            //关键是所有x个箱子里都要放满苹果
            else dp[i][x] = dp[i - 1][x - 1] + dp[i - x][x] ;
        }
    }cout << dp[n][k] ;
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 100 ;
int dp[MAXN][MAXN], sum[MAXN][MAXN], o[MAXN] ; 
//dp[i][j] 表示 低i位恰好出现j个1 的可能数
//sum[i][j] 表示 低i位最多出现 j个1 的可能数
int N, L, I ; 
//找所有 N 位二进制数中有 L 个1的第 I 小的数

void dfs(int len, int one, int rk){
    if(!len) {
        for(int i = N ; i >= 1 ; i--) cout << o[i] ;
        exit(0) ;
    }
    //sum[len - 1][one] 表示 len 位取0，更低位共取 one 个 1 的方案数
    //也即 len 位取0，最大能排第几名
    if(sum[len - 1][one] < rk){
        o[len] = 1 ;
        //cout << "cnm " ;
        dfs(len - 1, one - 1, rk - sum[len - 1][one]) ;
    }else {
        o[len] = 0 ;
        //cout << "nmd " ;
        dfs(len - 1, one, rk) ;
        //dfs(len - 1, one - 1, sum[len - 1][L - one - 1]) ;
    }
}

signed main() {
    cin >> N >> L >> I ;
    
    dp[0][0] = 1 ;
    for(int i = 1 ; i <= N ; i++){
        dp[i][0] = 1 ;
        //dp[i][i] = 1 ;
        for(int j = 1 ; j <= N ; j++){
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] ;
        }
    }

    // for(int i = 1 ; i <= N ; i++){
    //     for(int j = 1 ; j <= i ; j++) {
    //         cout << dp[i][j] << ' ' ; 
    //     }
    //     cout << endl ;
    // }cout << endl ;

    for(int i = 0 ; i <= N ; i++){
        for(int j = 0 ; j <= N ; j++){
            for(int k = 0 ; k <= j ; k++){
                sum[i][j] += dp[i][k] ;
            }
        }
    }

    // for(int i = 1 ; i <= N ; i++){
    //     for(int j = 1 ; j <= i ; j++) {
    //         cout << sum[i][j] << ' ' ; 
    //     }
    //     cout << endl ;
    // }cout << endl ;

    dfs(N, L, I) ;
    return 0 ; 
}
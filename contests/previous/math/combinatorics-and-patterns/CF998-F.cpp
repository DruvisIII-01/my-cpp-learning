#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int Mod =  998244353 ;
int q_pow(int a, int x){
    int res = 1, mul = a ;
    while(x){
        if(x & 1) res = (res * mul % Mod) ;
        mul = mul * mul % Mod ;
        x >>= 1 ; 
    }
    return res % Mod ;
}

int inv(int x) {return q_pow(x, Mod - 2) ; } 
int C(int k, int n){
    int res = 1 ;
    for(int t = n ; t >= n - k + 1 ; t--) res = res * t % Mod ; 
    for(int t = 1 ; t <= k ; ++t) res = res * inv(t) % Mod ; 
    return res % Mod ;
} 

void solve(){
    int k, n ; cin >> k >> n ;
    cout << n << ' ' ;//special judge for x == 1
    //dp[pro][len] = sum of dp[d][len - 1]
    //where d > 2 and !(pro % d)
    vector<vector<int>> dp(k + 1, vector<int>(30)) ;
    dp[1][1] = 0 ;
    for(int pro = 2 ; pro <= k ; ++pro) dp[pro][1] = 1 ;
    // for(int len = 2 ; len < 19 ; ++len){
    //     for(int pro = 1 ; pro <= k ; ++pro){
    //         for(int d = 2 ; d * d <= pro ; d++){
    //             if(pro % d == 0) {
    //                 dp[pro][len] = (dp[pro][len] + dp[pro / d][len - 1]) % Mod ;
    //                 if(d * d != pro)
    //                 dp[pro][len] = (dp[pro][len] + dp[d][len - 1]) % Mod ; 
    //             }
    //         }
    //     }
    // }
    for(int len = 2 ; len < 19 ; ++len){
        for(int p = 1 ; p <= k ; ++p){
            for(int t = p + p ; t <= k ; t += p)
            dp[t][len] = (dp[t][len] + dp[p][len - 1] + Mod) % Mod ;
        }
    }
    vector<int> comb(30) ;
    for(int t = 1 ; t < 20 ; ++t) comb[t] = C(t, n + 1) ; 
    for(int x = 2 ; x <= k ; ++x){
        int ans = 0 ; 
        for(int len = 1 ; len < 19 ; len++)
        ans = (ans + comb[len + 1] * dp[x][len]) % Mod ;
        cout << ans << ' ' ;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
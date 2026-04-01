#include <bits/stdc++.h>
using namespace std ;

#define int long long

int dp[100][100][2] ;

int dfs(int len, int sum, bool is_num){
    if(!len) return (int)(is_num) ;
    int ans = 0, start = (int)(is_num == 0) ;
    if(!is_num){
        if(dp[len - 1][sum][0] != -1) ans += dp[len - 1][sum][0] ;
        else {
            int tmp1 = dfs(len - 1, sum, false) ;
            ans += tmp1 ;
            dp[len - 1][sum][0] = tmp1 ;
        }
    }
    for(int i = start ; i < 10 ; i++){
        if(sum >= i) {
            if(dp[len - 1][sum - i][1] != -1) ans += dp[len - 1][sum - i][1] ;
            else {
                int tmp2 = dfs(len - 1, sum - i, true) ;
                ans += tmp2 ;
                dp[len - 1][sum - i][1] = tmp2 ;
            }
        }else break ;
    }return ans ;
}

void solve(){
    int n, k ; cin >> n >> k ;
    memset(dp, -1, sizeof(dp)) ;
    int ans = dfs(n, k, false) ;
    cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
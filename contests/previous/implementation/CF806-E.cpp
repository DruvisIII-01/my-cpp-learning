#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<string> mp(n) ;
    int ans = 0 ;
    for(int t = 0 ; t < n ; ++t) cin >> mp[t] ;
    // printf("n = %d, I = %d, J = %d\n", n, n / 2, (n - 1) / 2) ;
    int I = 0, J = 0 ;
    if(n % 2) {
        I = n / 2 ; 
        J = n / 2 - 1 ;
    }else{
        I = n / 2 - 1 ;
        J = n / 2 - 1 ;
    }
    // for(int i = 0 ; i <= I ; ++i){
    //     for(int j = 0 ; j <= J ; ++j){
    //         cout << mp[i][j] << ' ' << mp[n - 1 - j][i] << ' '
    //         << mp[j][n - 1 - i] << ' ' << mp[n - 1 - i][n - 1 - j] ;
    //         cout << endl ;
    //     }
    // }
    for(int i = 0 ; i <= I ; i++){
        for(int j = 0 ; j <= J ; j++){
            int sum = mp[i][j] + mp[n - 1 - j][i] + 
            mp[j][n - 1 - i] + mp[n - 1 - i][n - 1 - j] ;
            sum -= '0' * 4 ;
            ans += min(sum, 4 - sum) ;
        }
    }cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
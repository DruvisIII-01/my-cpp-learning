#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool is_prime(int x){
    if(x == 1) return false ;
    if(x == 2) return true ;
    if(x % 2 == 0) return false ;
    for(int i = 3 ; i * i <= x ; i += 2){
        if(x % i == 0) return false ;
    }return true ;
} 

signed main() {
    int T ;cin >> T ;

    map<int, bool> isPrime ;
    vector<int> primes ;
    vector<vector<int>> spf(200000) ;
    for(int i = 1 ; i <= 200000 ; ++i) {
        isPrime[i] = is_prime(i) ;
        if(isPrime[i] && i <= 200000) {
            primes.push_back(i) ;
        }
    }
    for(int prime : primes){
        for(int i = 1 ; i * prime <= 200000 ; ++i){
            spf[i * prime].push_back(prime) ;
        }
    }
    
    while(T--) {
        int n, k ; cin >> n >> k ;
        vector<int> a(n + 1) ;
        for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
        // sort(a.begin() + 1, a.end()) ;

        int ans = 0 ;
        vector<int> dp(n + 1, 200000) ;
        for(int i = 1 ; i <= n ; ++i){
            if(i <= k) {
                dp[i] = 0 ;
                continue ;
            }
            for(int p : spf[i]){
                dp[i] = min(dp[i], 1 + p * dp[i / p]) ;
            }
        }

        for(int i = 1 ; i <= n ; ++i) ans += dp[a[i]] ;
        cout << ans << endl ;
    }
    return 0;
}
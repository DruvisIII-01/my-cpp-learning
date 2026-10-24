#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 500005 ;
const int mod = 1000000007 ;
int spf[MAXN] ;

signed main() {
    for(int t = 2 ; t < MAXN ; ++t){
        if(!spf[t]){
            spf[t] = t ;
            for(int i = t * t ; i < MAXN ; i += t){
                if(!spf[i]) spf[i] = t ;
            }
        }
    }
    
    int T ;cin >> T ;
    while(T--) {
        int n, x ; cin >> n >> x ;
        vector<int> a(n + 1) ;
        map<int, int> cnt ;
        vector<int> touched ;
        for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

        int ans = 1 ; 
        for(int t = 1 ; t <= n ; ++t) {
            int tmp = a[t] ;
            while(tmp > 1){
                int p = spf[tmp] ;
                if(!cnt[p]) touched.push_back(p) ;
                cnt[p]++ ;
                tmp /= p ;
            }
        }
        for(int p : touched) {
            ans = ans * (1 + cnt[p]) ;
            ans %= mod ;
        }
        cout << ans << endl ; 
    }
    return 0;
}
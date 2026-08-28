#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    vector <int> a(n + 1) ; for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    vector <int> sum(n + 1) ; for(int t = 1 ; t <= n ; ++t) sum[t] = a[t] + sum[t - 1] ;
    vector <int> h(n + 1) ; for(int t = 1 ; t <= n ; ++t) cin >> h[t] ;

    int right = 1 ; 
    int ans = 0 ; 
    for(int left = 1 ; left <= n ; ++left){
        // printf("left = %d, right = %d.\n", left, right) ;
        if(right <= left) right = left + 1 ;
        // printf("left = %d, right = %d.\n", left, right) ;
        while(right < n + 1 && h[right - 1] % h[right] == 0){
            right++ ;
        }//printf("left = %d, right = %d.\n", left, right) ;
        if(left + 1 == right && a[left] > k) continue ;
        int L = left - 1 ; int R = right ;
        while(L + 1 != R){
            int M = (R + L) >> 1 ; 
            if((sum[M] - sum[left - 1]) <= k) L = M ;
            else R = M ;  
        }int cur = L - left + 1 ; 
        // printf("L = %d, cur = L - left + 1 = %d.\n", L, cur) ;
        ans = max(cur, ans) ;
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
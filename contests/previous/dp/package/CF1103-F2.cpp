#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 500005 ;
const int mod = 1000000007 ;
int spf[MAXN] ;

bool is_prime(int x){
    if(x == 1) return false ;
    if(x == 2) return true ;
    if(x % 2 == 0) return false ;
    for(int i = 3 ; i * i <= x ; i += 2){
        if(x % i == 0) return false ;
    }return true ;
}

int v(int p, int n){
    int res = 0 ;
    while(n % p == 0){
        res++ ;
        n /= p ;
    }return res ;
}

int calc(int S, int L, vector<int>& c){
    if(S < 0) return 0 ;
    int n = c.size() - 1 ;
    vector<int> dp(S + 1) ;
    dp[0] = 1 ;

    for(int i = 1 ; i <= n ; ++i){
        int lim = min(c[i], L) ;
        for(int j = S ; j >= 1 ; j--){
            for(int k = 1 ; k <= min(j, lim) ; ++k){
                dp[j] += dp[j - k] ;
                dp[j] = (dp[j] + mod) % mod ;
            } 
        }
    }
    return dp[S] ;
}

void solve(){
    int n, x ; cin >> n >> x ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    vector<int> primex ;
    map<int, int> cnt ;
    for(int i = 1 ; i * i <= x ; ++i){
        if(x % i == 0){
            if(is_prime(i)){
                primex.push_back(i) ;
                cnt[i] = v(i, x) ;
            }
            if(x / i != i && is_prime(x / i)){
                primex.push_back(x / i) ;
                cnt[x / i] = v(x / i, x) ;
            }
        }
    }
    // for(int p : primex) cout << p << ' ' << cnt[p] << endl ;

    int ans = 1 ;
    for(int p : primex){
        int W = cnt[p], mx = 0 ;
        //mx表示c数组中的最大值
        vector<int> c(n + 1) ;
        //c[t]表示a[t]含有因子p的阶数
        for(int t = 1 ; t <= n ; ++t){
            c[t] = v(p, a[t]) ;
            //cout << c[t] << ' ' ;
            mx = max(mx, c[t]) ;
        }
        //cout << endl << mx << endl ;
        int C = (W == 0) ;
        for(int M = mx ; M >= 1 ; M--){
            int S = M + W ;
            C += calc(S, M, c) - calc(S, M - 1, c) ;
            C = (C + mod) % mod ;
        }ans = (C * ans + mod) % mod ;
    }

    vector<int> freep ;
    map<int, int> cnt_fp ;
    for(int t = 1 ; t <= n ; ++t){
        int tmp = a[t] ;
        while(tmp > 1){
            int fp = spf[tmp] ;
            if(!cnt[fp]){
                if(!cnt_fp[fp]) freep.push_back(fp) ;
                cnt_fp[fp]++ ;
            }
            tmp /= fp ;
        }
    }
    for(int fp : freep) {
        ans = (ans * (cnt_fp[fp] + 1) + mod) % mod ;
        //cout << fp << ' ' << cnt_fp[fp] << endl ;
    }
    cout << ans ;
}

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
        solve() ;
        cout << endl ;
    }
    return 0;
}
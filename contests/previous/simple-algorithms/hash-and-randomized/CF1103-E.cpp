#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> dist(1, 10000000);

    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    vector<int> hsh(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) hsh[t] = dist(gen) ;
    vector<int> pre(n + 1) ; 
    for(int t = 1 ; t <= n ; ++t) pre[t] = pre[t - 1] + hsh[a[t]] ;
    vector<int> prex(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) prex[t] = prex[t - 1] + hsh[t] ;

    vector<vector<bool>> inv(n + 1, vector<bool>(n + 1)) ;
    for(int i = 1 ; i <= n ; ++i){
        int mi = n + 1 ;
        for(int j = i ; j <= n ; ++j){
            mi = min(mi, a[j]) ;
            int len = j - i + 1 ;
            
            int sum = pre[j] - pre[i - 1] ; 
            int sumx = prex[mi + len - 1] - prex[mi - 1] ;
            
            if(sum == sumx) inv[mi][len] = true ;
        }
    }
    for(int ans = n / 2 ; ans >= 1 ; ans--){
        for(int mi = 1 ; mi + ans * 2 - 1 <= n  ; ++mi){
            if(inv[mi][ans] && inv[mi + ans][ans]){
                cout << ans ;
                return ;
            }
        }
    }cout << 0 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
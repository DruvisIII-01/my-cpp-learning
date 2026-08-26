#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define pii pair<int, int>

const int inff = 1e9 + 7 ;

int isqrt(int x){
    int res = x ; 
    while(res){
        res-- ;
        if(res * res <= x) return res ;
    }return res ;
}
void solve(){
    int n, m ; cin >> n >> m ;
    vector<int> x(n + 1) ;for(int i = 1 ; i <= n ; ++i) cin >> x[i] ;
    vector<int> r(n + 1) ;for(int i = 1 ; i <= n ; ++i) cin >> r[i] ;
    map<int, int> mp ;

    for(int i = 1 ; i <= n ; ++i){
        for(int j = x[i] - r[i] ; j <= x[i] + r[i] ; j++){
            int y = (int)sqrt(r[i] * r[i] - (j - x[i]) * (j - x[i])) ;
            mp[j] = max(mp[j], 2 * y + 1) ;
        }
    }

    int ans = 0 ; for(auto [x, c] : mp) ans += c ;
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
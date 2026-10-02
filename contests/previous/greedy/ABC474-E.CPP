#include <bits/stdc++.h>
using namespace std ;

#define int long long
struct node{
    int a ;
    int b ;
}p[224524] ;
void solve(){
    int n ; cin >> n ; 
    for(int i = 1 ; i <= n ; ++i) {
        int x, y ; cin >> x >> y ;
        p[i].a = x ; p[i].b = y ;
    }
    auto cmp = [](const struct node& x, const struct node& y){
        return x.a - x.b > y.a - y.b ;
    }; sort(p + 1, p + n + 1, cmp) ;
    // cout << endl ; 
    // for(int i = 1 ; i <= n ; ++i) cout << p[i].a << ' ' << p[i].b << endl ;

    int mi = LLONG_MAX ;
    int m_idx = -1 ;
    for(int i = 1 ; i <= n ; ++i){
        if(p[i].a < mi){
            mi = p[i].a ;
            m_idx = i ;
        }
    }
    vector<int> preB(n + 1) ;
    vector<int> sufA(n + 2) ;
    for(int i = 1 ; i <= n ; ++i) preB[i] = preB[i - 1] + p[i].b ;
    for(int i = n ; i >= 1 ; i--) sufA[i] = sufA[i + 1] + p[i].a ;
    int ans = LLONG_MAX ;
    for(int k = n / 2 ; k <= n ; ++k){
        int cur = preB[k] + sufA[k + 1] ;
        if(k * 2 - n > 0){
            // cur += (k * 2 - n) * mi ;
            cur += (k * 2 - n) * mi ;
            // if(m_idx > k) cur -= p[m_idx].a ;
        }
        ans = min(ans, cur) ;
        // cout << k << "and" << cur << endl ;
    }cout << ans ;

    for(int i = 1 ; i <= n ; ++i) {
        p[i].a = 0 ;
        p[i].b = 0 ;
    }
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
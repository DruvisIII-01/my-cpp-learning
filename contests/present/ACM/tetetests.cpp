#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define pii pair<int, int>  
const int LIMIT = 20 ;

signed main() {
    int n, m ; cin >> n >> m ; 
    
    vector<pii> a(1) ;//sizeof(a) = 2 * n + 1
    for(int t = 1 ; t <= n ; ++t) {
        int x, y ; cin >> x >> y ;
        if(y < x){
            a.push_back({x, y + m}) ;
            a.push_back({x + m, y + 2 * m}) ;
        }else{
            a.push_back({x, y}) ;
            a.push_back({x + m, y + m}) ;
        }
    }sort(a.begin() + 1, a.end()) ;
    // for(int t = 1 ; t <= 2 * n ; ++t) cout << a[t].first << ' ' << a[t].second << endl ; 

    vector<vector<int>> st(2 * n + 1, vector<int>(LIMIT)) ;
    int right = 1 ;
    for(int left = 1 ; left <= 2 * n ; ++left){
        while(right <= 2 * n && a[right].first <= a[left].second){
            right++ ;
        }st[left][0] = right - 1 ;
        //cout << st[left][0] << ' ' ;
    }
    for(int d = 1 ; d < LIMIT ; ++d){
        for(int t = 1 ; t <= 2 * n ; ++t){
            int mid = st[t][d - 1] ;
            st[t][d] = st[mid][d - 1] ;
        }
    }

    for(int t = 1 ; t <= n ; ++t){
        int cur = t, ans = 0 ;
        for(int D = LIMIT - 1 ; D >= 0 ; D--){
            if(st[cur][D] < t + n) {
                cur = st[cur][D] ;
                ans += (1 << D) ;
            }
        }cout << ans + 1 << ' ' ;
    }
    return 0;
}
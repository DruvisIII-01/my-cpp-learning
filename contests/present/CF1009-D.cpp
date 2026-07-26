#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int inff = 1e9 + 7 ;
struct circle{int x ; int r ;} ;
struct interval { int st; int fi; };

void solve(){
    int n, m ; cin >> n >> m ;
    vector<circle>C(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> C[i].x ;
    for(int i = 1 ; i <= n ; ++i) cin >> C[i].r ;
    auto cmp_x = [](const circle C1, const circle C2){
        return C1.x < C2.x ;
    } ; sort(C.begin() + 1, C.begin() + n + 1, cmp_x) ;
    vector<vector<interval>>S(m + 1) ;
    for(int i = 1 ; i <= n ; ++i){
        int R = C[i].r, X = C[i].x ;
        //cout << i << R << X << endl ;
        for(int y = 0 ; y <= R ; ++y){
            int d = (int)sqrt(R * R - y * y) ;
            int nst = X - d, nfi = X + d ;
            // interval nitv ; nitv.st = nst ; nitv.fi = nfi ;
            // if(S[y].empty()) S[y].insert(nitv) ;
            // else{
            //     bool find = false ;
            //     int mi = inff, mx = -inff ;
            //     for(interval itv : S[y]){
            //         if(nst <= itv.fi){
            //             if(nst >= itv.st){
            //                 mi = min(mi, itv.st) ; mx = max({nfi, itv.fi, mx}) ;
            //                 S[y].erase(itv) ; find = true ;
            //             }else if(nfi >= itv.st){
            //                 mi = min(mi, nst) ; mx = max({nfi, itv.fi, mx});
            //                 S[y].erase(itv) ; find = true ;
            //             }
            //         }
            //     }if(!find)S[y].insert(nitv) ;
            //     else{
            //         interval to_add ; to_add.fi = mx ; to_add.st = mi ;
            //         S[y].insert(to_add) ;
            //     }
            // }
        }
    }//cout << "ccc" ;
    int ans = 0 ;
    for(int y = 0 ; y <= m ; ++y){
        int sum = 0 ;
        for(interval itv : S[y]) sum += itv.fi - itv.st + 1 ;
        if(!y) ans += sum ; else ans += 2 * sum ;
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
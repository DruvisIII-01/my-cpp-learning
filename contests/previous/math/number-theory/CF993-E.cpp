// l2 / r1 <= q <= r2 / l1
// Q[K] // k 100 
// let q0 = Q[0]
// [l1, r1] intersects [l2 / q0, r2 / q0]
#include <bits/stdc++.h>
using namespace std ;

#define int long long
const double eps = 1e-6 ;

void solve(){
    int k, l1, r1, l2, r2 ; cin >> k >> l1 >> r1 >> l2 >> r2 ;
    vector<int> Q ; 
    int power = 1 ;
    if(power * r1 >= l2 && power * l1 <= r2) Q.push_back(power) ;
    for(int t = 1 ; t <= 32 ; t++){
        power *= k ;
        if(power * r1 >= l2 && power * l1 <= r2) Q.push_back(power) ;
        if(power * l1 > r2) break ;
    }
    //for(int q : Q) cout << q << endl ;
    
    int ans = 0 ;
    for(int q : Q){
        int nl2 = (l2 + q - eps) / q ; int nr2 = r2 / q ;
        //cout << nl2 << ' ' << nr2 << endl ;
        ans += (min(nr2, r1) - max(nl2, l1)) + 1 ;
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
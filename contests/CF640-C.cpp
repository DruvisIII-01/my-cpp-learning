#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    int t1 = k/(n-1), t2 = k%(n-1) ;
    if(t2 == 0) {
        t2 = n-1 ;
        t1-- ;
    }
    cout << t1*n + t2 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
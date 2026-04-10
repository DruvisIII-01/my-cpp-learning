#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    int tt = n * (2 * k + n - 1) / 2 ; 
    int L = 0, R = n + 1 ;
    while(R != L + 1){
        int M = (L + R) >> 1 ; 
        int cp = (2 * k + M - 1) * M ;
        if(cp >= tt) R = M ;
        else L = M ;
    }
    int a1 = abs(tt - L * (2 * k + L - 1)) ;
    int a2 = abs(tt - R * (2 * k + R - 1)) ;
    cout << min(a1, a2) ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
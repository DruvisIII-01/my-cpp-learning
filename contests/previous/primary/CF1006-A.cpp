#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k, p ; cin >> n >> k >> p ;
    int mi = - p * n, mx = p * n ;
    if(mx < k || mi > k){
        cout << '-' << '1' ;
        return ;
    }
    k = abs(k) ;
    cout << (k + p - 1) / p ; 
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
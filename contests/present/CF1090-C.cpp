#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    //1, 3n-1, 3n, 2, 3n-3, 3, 3n-5, ... , n, 2n,  
    for(int i = 1 ; i <= n ; i++){
        cout << i << ' ' << 3 * n - 2 * i + 1 << ' ' << 3 * n - i * 2+ 2 << ' ' ; 
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
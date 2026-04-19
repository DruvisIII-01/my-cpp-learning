#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    for(int i = 1 ; i <= n ; i++) {
        int x = (i + 1 + n) % n ;
        if(x == 0) x = n ;
        cout << x << ' ' ;
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
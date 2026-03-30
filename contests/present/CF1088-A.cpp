#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    for(int i = 1 ; i <= n ; i++) {
        int x ; cin >> x ;
    }
    if(n == 1) {
        cout << 1 ;
        return ;
    }
    for(int i = 1 ; i <= n ; i++){
        cout << 2 << ' ' ;
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
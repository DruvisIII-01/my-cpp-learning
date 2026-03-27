#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    for(int i = 1 ; i <= n ; i++){
        int mx = 0, mi = 0 ;
        for(int j = i + 1 ; j <= n ; j++){
            mx += (a[j] > a[i]) ;
            mi += (a[j] < a[i]) ;
        }
        cout << max(mx, mi) << ' ';
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
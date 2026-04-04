#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
    }int ans = -1 ;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = i + 1 ; j <= n ; j++){
            ans = max(ans, a[i]^a[j]) ;
        }
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
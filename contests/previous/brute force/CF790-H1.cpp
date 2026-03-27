#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        for(int j = 1 ; j < i ; j++){
            ans += (a[j] >= a[i]) ;
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

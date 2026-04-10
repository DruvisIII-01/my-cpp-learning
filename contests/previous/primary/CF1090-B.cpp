#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a[7] ;
    for(int i = 0 ; i <= 6 ; i++) cin >> a[i] ;
    sort(a, a+7) ;
    a[6] = -a[6] ;
    int ans = 0 ;
    for(int i = 0 ; i <= 6 ; i++) ans -= a[i] ;
    cout << ans ; 
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
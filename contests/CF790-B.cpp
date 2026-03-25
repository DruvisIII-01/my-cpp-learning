#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    int sum = 0, mi = LLONG_MAX ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        mi = min(a[i], mi) ;
        sum += a[i] ;
    }
    cout << sum - mi * n ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
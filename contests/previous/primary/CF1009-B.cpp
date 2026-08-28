#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ; 
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
    int sum = 0 ; 
    for(int i = 1 ; i <= n ; ++i) sum += a[i] ;
    cout << sum - (n - 1) ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
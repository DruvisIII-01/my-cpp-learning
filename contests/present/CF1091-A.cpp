#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    vector <int> a(n + 1) ;
    int sum = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
        sum += a[i] ;
    }
    bool win_without = (sum % 2 == 1) ;
    bool win_with = (n * k % 2 == 0) ;
    if(win_without || win_with) cout << "YES" ;
    else cout << "NO" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
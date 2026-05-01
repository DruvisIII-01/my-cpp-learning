#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    vector <int> b ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    for(int i = 1 ; i <= n ; i++) {
        if(a[i] % 6 == 0) b.push_back(a[i]) ;
    }
    for(int i = 1 ; i <= n ; i++) {
        if(a[i] % 2 == 0 && a[i] % 3 != 0) b.push_back(a[i]) ;
    }
    for(int i = 1 ; i <= n ; i++) {
        if(a[i] % 2 != 0 && a[i] % 3 != 0) b.push_back(a[i]) ;
    }
    for(int i = 1 ; i <= n ; i++) {
        if(a[i] % 2 != 0 && a[i] % 3 == 0) b.push_back(a[i]) ;
    }
    for(auto x : b) cout << x << ' ' ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
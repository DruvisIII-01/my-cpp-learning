#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ; 
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    int mx = 1, cur = 1 ;
    for(int i = 2 ; i <= n ; i++) {
        if(a[i] == a[i - 1]) {
            cur++ ;
            if(i == n) mx = max(cur, mx) ;
        }else{
            mx = max(mx, cur) ;
            cur = 1 ; 
        }
    }if(mx >= m) cout << "NO" ;
    else cout << "YES" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
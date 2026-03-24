#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    bool odd1 = true, even1 = true ;
    int x1 = a[1] % 2, x2 = a[2] % 2 ;
    for(int i = 3 ; i <= n ; i++){
        int xi = a[i] % 2 ;
        if(i % 2 == 1) {
            if(xi != x1) {
                odd1 = false ;
                break ;
            }
        }else {
            if(xi != x2) {
                even1 = false ;
                break ;
            }
        }
    }
    if(even1 && odd1) cout << "YES" ;
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
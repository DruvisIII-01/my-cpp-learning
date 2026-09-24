#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    int rest = 0 ;
    bool ans = true ;
    for(int i = 1 ; i <= n ; ++i){
        if(a[i] >= i) rest += (a[i] - i) ;
        else {
            if(rest + a[i] < i) {
                ans = false ;
                break ;
            }else rest -= (i - a[i]) ;
        }
    }

    if(ans) cout << "YES" ;
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
#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k, p ; cin >> n >> k ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    cin >> p ;
    int tmpL = a[p], tmpR = a[p] ;
    int cntL = 0, cntR = 0 ;
    for(int i = p - 1 ; i >= 1 ; i--){
        if(tmpL != a[i]){
            cntL++ ;
            tmpL = a[i] ;
        }
    }
    for(int i = p + 1 ; i <= n ; i++){
        if(tmpR != a[i]){
            cntR++ ;
            tmpR = a[i] ;
        }
    }
    int ans = max(cntR, cntL) ;
    if(ans % 2 == 1) ans++ ;
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
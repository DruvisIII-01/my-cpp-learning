#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n+1,0) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    int ans = 1, tmp = a[1] ;
    for(int i = 2 ; i <= n ; i++) {
        if(a[i] >= tmp){
            ans++;
            tmp = a[i] ;
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
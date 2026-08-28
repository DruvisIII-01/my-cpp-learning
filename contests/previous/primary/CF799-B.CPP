#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    vector <int> hsh(114514) ;
    int ans = 0 ;
    int odd = 0 ;
    int even = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i] ;
        hsh[a[i]]++ ;
    }for(int x : hsh){
        if(!x) continue ;
        if(x % 2) odd++ ;
        if(x % 2 == 0) even++ ;
    }ans = odd + (even / 2) * 2 ;
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
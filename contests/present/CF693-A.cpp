#include <bits/stdc++.h>
using namespace std ;

#define int long long

int calc(int x){
    int res = 1 ;
    while(x % res == 0) res <<= 1 ;
    return (res >> 1) ;
}

void solve(){
    int w, h, n ; cin >> w >> h >> n ;
    int mx = calc(w) * calc(h) ;
    if(mx >= n) cout << "YES" ;
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
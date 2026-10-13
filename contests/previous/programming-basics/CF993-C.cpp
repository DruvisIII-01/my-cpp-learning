#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int m, a, b, c ; cin >> m >> a >> b >> c ;
    int ans = 0 ;
    if(m <= a) ans += m ;
    else{
        if(a + c >= m){
            c -= (m - a) ;
            ans += m ;
        }else{
            ans += (a + c) ;
            c = 0 ;
        }
    }
    // cout << a << ' ' << b << ' ' << c << ' ' ;
    // cout << ans << endl ;
    if(m <= b) ans += m ;
    else{
        if(b + c >= m){
            c -= (m - b) ;
            ans += m ;
        }else{
            //cout << "ooo" ;
            ans += (b + c) ;
            c = 0 ;
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
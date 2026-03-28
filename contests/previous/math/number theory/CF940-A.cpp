#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int x, y ; cin >> x >> y ;
    if(x == 0 && y != 0) cout << (y + 1) / 2 ;
    else if(x != 0 && y == 0) cout << (x + 14) / 15 ;
    else if(x == 0 && y == 0) cout << 0 ;
    else{
        int cnt2 = (y + 1) / 2 ;
        int rest = 0 ;
        if(y % 2 == 0) rest = x - cnt2 * 7 ;
        else rest = x - (cnt2 - 1) * 7 - 11 ;
        if(rest <= 0) cout << cnt2 ;
        else cout << cnt2 + (rest + 14) / 15 ;
    }
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int h, w, q ; cin >> h >> w >> q ;
    while(q--){
        int op, delta ; cin >> op >> delta ;
        if(op == 1){
            cout << delta * w << endl ;
            h -= delta ;
        }else {
            cout << delta * h << endl ;
            w -= delta ;
        }
    }
    return 0;
}
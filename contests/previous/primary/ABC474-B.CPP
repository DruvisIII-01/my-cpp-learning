#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n ; cin >> n ;
    bool is_ok = true ;
    for(int i = 1 ; i <= n ; ++i){
        int order ; cin >> order ;
        if(order > (i + 9) / 10 * 10) {
            is_ok = false ;
            break ;
        }
    }if(is_ok) cout << "Yes" ;
    else cout << "No" ;
    return 0;
}
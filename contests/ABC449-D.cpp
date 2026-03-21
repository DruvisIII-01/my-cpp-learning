#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int L, R, D, U ; cin >> L >> R >> D >> U ;
    int ans = 0 ;
    //|x| >= |y| 
    for(int x = L ; x <= R ; x++){
        //不可以用if(x % 2 == 1) continue ;
        //因为x % 2 可能为 -1
        if(x % 2 == 0){
            int u = min(abs(x), U) ;
            int d = max(-abs(x), D) ;
            ans += max(u - d + 1, (int)0) ;
        }
    }
    //|x| < |y|
    for(int y = D ; y <= U ; y++){
        if(y % 2 == 0){
            int l = max(-abs(y) + 1, L) ;
            int r = min(abs(y) - 1, R) ;
            ans += max(r - l + 1, (int)0) ;
        }
    }
    cout << ans ;
    return 0;
}
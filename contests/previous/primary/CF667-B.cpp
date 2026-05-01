#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, x, y, n ; cin >> a >> b >> x >> y >> n ;
    int da = a - x, db = b - y ;
    if(da + db <= n) cout << x * y ;
    else{
        int up = min(n, a - x) ;
        int down = max((int)0, n + y - b) ;
        int ans1 = (a - down) * (b - n + down) ;
        int ans2 = (a - up) * (b - n + up) ;
        cout << min(ans1, ans2) ; 
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
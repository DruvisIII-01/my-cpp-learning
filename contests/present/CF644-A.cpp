#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b ; cin >> a >> b ;
    int ans = min(
        max(a, b + b), max(b, a + a) 
    ) ; cout << ans * ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
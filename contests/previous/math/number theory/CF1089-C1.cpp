#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n; cin >> n;
    vector <int> a(n + 1);
    vector <int> b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    // int x0 = gcd(a[1], a[2]), y0 = gcd(a[n - 1], a[n]),
    // ans = (a[1] != x0) + (a[n] != y0);
    // for(int i = 2; i <= n - 1; i++) {
    //     int x = gcd(a[i - 1], a[i]), y = gcd(a[i], a[i + 1]);
    //     if(x == y) ans += (a[i] != x); 
    // }cout << ans;
    vector <int> x(n + 1);
    for(int i = 1; i <= n - 1; i++) x[i] = gcd(a[i], a[i + 1]) ;
    int ans = (a[1] != x[1]) + (a[n] != x[n - 1]);
    for(int i = 2; i <= n - 1; i++) {
        // if(x[i - 1] == x[i]) ans += (a[i] != x[i]) ;
        int need = (x[i - 1] * x[i]) / gcd(x[i - 1], x[i]);
        if(need < a[i]) ans++;
    }cout << ans;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
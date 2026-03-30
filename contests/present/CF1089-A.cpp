#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n; cin >> n;
    for(int i = n; i >= 1; i--) cout << i << ' ';
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
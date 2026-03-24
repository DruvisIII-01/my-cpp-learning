#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    vector <int> hsh(n + 1) ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
        hsh[a[i]]++ ;
    }
    for(int i = 1 ; i <= n ; i++) {
        if(hsh[i] >= 3) {
            cout << i ;
            return ;
        }
    }
    cout << '-' << 1 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
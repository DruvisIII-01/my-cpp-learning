#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a[3] = {} ; cin >> a[0] >> a[1] >> a[2] ;
    sort(a, a + 3) ;
    if((a[0] < a[1] && a[1] < a[2]) || (a[0] == a[1] && a[1] < a[2])) {
        cout << "NO" ;
        return ;
    }
    cout << "YES" << endl ;
    cout << a[0] << ' ' << a[2]<< ' ' << a[0] ;
} 

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
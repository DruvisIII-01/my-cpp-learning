#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    int ans1 = 0 ;
    int ans2 = 0 ;
    int ans3 = 0 ;
    for(int i = 1 ; i <= n ; ++i) {
        int T = (a[i] + 999) / 1000 ;
        int change = T * 1000 - a[i] ;
        //cout << change << endl ;
        
        ans3 += change / 100 ; 
        change %= 100 ;
        ans2 += change / 10 ;
        change %= 10 ;
        ans1 += change ;
    }
    cout << ans1 << ' ' << ans2 << ' ' << ans3 ;
    return 0;
}
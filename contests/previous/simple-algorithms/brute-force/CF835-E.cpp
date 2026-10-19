#include <bits/stdc++.h>
using namespace std ;

#define int long long

void P(vector<int>&a){
    cout << "============" << endl ; 
    for(int x : a) cout << x << ' ' ;
    cout << endl << "============" << endl ; 
}

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    vector<int> pre1(n + 1) ;
    vector<int> aft0(n + 2) ;
    for(int t = 1 ; t <= n ; ++t) pre1[t] = pre1[t - 1] + a[t] ;
    for(int t = n ; t >= 1 ; t--) aft0[t] = aft0[t + 1] + 1 - a[t] ;

    int ans = 0 ;
    for(int t = 1 ; t <= n ; ++t) ans += (1 - a[t]) * pre1[t - 1] ;
    int tmp = ans ;
    for(int t = 1 ; t <= n ; ++t) {
        int cur ;
        if(a[t]) cur = tmp + pre1[t - 1] - aft0[t + 1] ;
        else cur = tmp + aft0[t + 1] - pre1[t - 1] ;
        ans = max(ans, cur) ;
    }cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
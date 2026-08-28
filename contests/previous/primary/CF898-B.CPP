#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;

    int mul = 1 ;
    int zero = 0 ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        zero += (a[t] == 0) ;
    }
    for(int t = 1 ; t <= n ; ++t) {
        if(a[t]) mul *= a[t] ;
    }
    //zero judge
    if(zero >= 2) {
        cout << 0 ;
        return ;
    }if(zero == 1){
        cout << mul ;
        return ;
    }
    int mx = -1 ; 
    for(int t = 1 ; t <= n ; ++t){
        int cur = mul / a[t] * (a[t] + 1) ;
        mx = max(mx, cur) ;
    } 
    cout << mx ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
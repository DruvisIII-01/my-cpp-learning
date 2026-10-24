#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    vector<int> a(n + 1) ;
    string s ; cin >> s ; s = '*' + s ;
    for(int t = 1 ; t <= n ; ++t) a[t] = (s[t] == '1') ;

    for(int t = n ; t >= k + 1 ; t--){
        if(a[t]){
            a[t] = 0 ;
            a[t - k] = 1 - a[t - k] ;
        }
    }
    bool ans = true ;
    for(int t = 1 ; t <= k ; ++t){
        if(a[t]){
            ans = false ;
            break ;
        }
    }if(ans) cout << "YES" ;
    else cout << "NO" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) {cin >> a[i] ;}
    sort(a.begin() + 1, a.begin() + n + 1) ;
    int mi = 1e9 + 114514 ;
    for(int i = 2 ; i <= n ; i++){
        mi = min(mi, a[i] - a[i - 1]) ;
    }cout << mi ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
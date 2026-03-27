#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ;
    vector <string> s(n + 1) ;
    for(int i = 1 ; i <= n ; i++){
        cin >> s[i] ;
    }
    int mi = LLONG_MAX ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = i + 1 ; j <= n ; j++){
            int cur = 0 ;
            for(int k = 0 ; k < m ; k++){
                cur += abs((int)s[i][k] - (int)s[j][k]) ;
            }
            mi = min(mi, cur) ;
        }
    }
    cout << mi ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
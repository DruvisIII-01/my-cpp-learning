#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ;
    int a[222][222] = {} ;
    vector <int> kn(1000) ;
    vector <int> kp(1000) ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j] ;
            kn[i - j + n + m] += a[i][j] ;
            kp[i + j] += a[i][j] ;
        }
    }
    int mx = -1 ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            //cout << kp[i + j] + kn[i - j + m + n] - a[i][j] << ' ' ;
            mx = max(mx, kp[i + j] + kn[i - j + m + n] - a[i][j]) ;
        }
        //cout << endl ;
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
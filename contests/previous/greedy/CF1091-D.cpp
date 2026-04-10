#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ; 
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    vector <int> p(k + 2) ;
    p[k + 1] = n + 1 ; 
    for(int i = 1 ; i <= k ; i++) cin >> p[i] ;
    int v = a[p[1]] ;
    vector <int> b(n + 2) ;
    b[0] = 1, b[n + 1] = 1 ;
    for(int i = 1 ; i <= n ; i++) b[i] = (a[i] == v) ;

    int s = 0, x = 0 ;
    for(int i = 0 ; i <= k ; i++){
        int cur = 0 ;
        for(int j = p[i] ; j < p[i + 1] ; j++) {
            if(b[j] != b[j + 1]){
                cur++ ;
                s++ ;
            }
        }
        x = max(x, cur) ;
    }cout << max(s / 2, x) ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
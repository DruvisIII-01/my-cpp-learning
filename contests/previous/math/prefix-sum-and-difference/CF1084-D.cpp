#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, x, y ; cin >> n >> x >> y ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    int mi_mid = n + 1 ;
    int mi_mid_i = -1 ;
    for(int t = x + 1 ; t <= y ; ++t){
        if(a[t] < mi_mid){
            mi_mid = a[t] ;
            mi_mid_i = t ;
        }
    }

    int mx_frt = 0 ;
    for(int t = 1 ; t <= x ; ++t) mx_frt = max(mx_frt, a[t]) ;
    if(mx_frt < mi_mid){
        for(int t = 1 ; t <= x ; ++t) cout << a[t] << ' ' ;
        int end = n + 1 ;
        for(int t = y + 1 ; t <= n ; ++t) {
            if(a[t] < mi_mid) cout << a[t] << ' ' ;
            else {
                end = t ;
                break ;
            } 
        }
        for(int t = mi_mid_i ; t <= y ; ++t) cout << a[t] << ' ' ;
        for(int t = x + 1 ; t < mi_mid_i ; ++t) cout << a[t] << ' ' ;
        for(int t = end ; t <= n ; ++t) cout << a[t] << ' ' ;
    }else{
        int start = x + 1 ; 
        for(int t = 1 ; t <= x ; ++t) {
            if(a[t] < mi_mid) cout << a[t] << ' ' ;
            else {
                start = t ;
                break ;
            }
        }
        for(int t = mi_mid_i ; t <= y ; ++t) cout << a[t] << ' ' ;
        for(int t = x + 1 ; t < mi_mid_i ; ++t) cout << a[t] << ' ' ;
        for(int t = start ; t <= x ; ++t) cout << a[t] << ' ' ;
        for(int t = y + 1 ; t <= n ; ++t) cout << a[t] << ' ' ; 
    } 
} 

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
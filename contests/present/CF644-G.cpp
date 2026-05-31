#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m, a, b ; cin >> n >> m >> a >> b ;
    //to judge whether exists a 0-1 matrix of n * m
    //each hang has a 1, and each lie has b 1
    if(a > m || b > n) {
        cout << "NO" << endl ;
        return ; 
    }
    if(a * n != b * m) {
        cout << "NO" << endl ;
        return ;
    }
    cout << "YES" << endl ;
    int ans[n][m] = {} ;
    for(int i = 0 ; i < n ; ++i){
        int st = i * a % m, fi = (i * a + a - 1) % m ;
        // cout << st << ' ' << fi << endl ;
        if(st <= fi){
            for(int j = 0 ; j < m ; ++j){
                if(st <= j && j <= fi) cout << 1 ;
                else cout << 0 ;
                // cout << ' ' ;
            }
        }else{
            for(int j = 0 ; j < m ; ++j){
                if(j >= st || j <= fi) cout << 1 ;
                else cout << 0 ;
                // cout << ' ' ;
            }
        }
        cout << endl ;
    }
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        // cout << endl ;
    }
    return 0;
}
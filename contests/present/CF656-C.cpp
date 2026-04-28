#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(2 * n + 1) ;
    vector <bool> vis(n + 1) ;
    for(int i = 1 ; i <= 2 * n ; i++){
        cin >> a[i] ;
        if(!vis[a[i]]){
            vis[a[i]] = true ;
            cout << a[i] << ' ' ;
        }
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
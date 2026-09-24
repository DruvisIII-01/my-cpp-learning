#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    int cnt0 = 0 ;
    for(int i = 1 ; i <= n ; ++i) cnt0 += (a[i] == 0) ;

    if(!cnt0){
        cout << "YES" << endl ;
        for(int i = 1 ; i <= n ; ++i) cout << 'A' ;
    }else if(cnt0 == 1) cout << "NO" ;
    else {
        cout << "YES" << endl ;
        bool first = false ;
        for(int i = 1 ; i <= n ; ++i){
            if(a[i] > 0 ) cout << 'C' ;
            else{
                if(!first){
                    cout << 'A' ;
                    first = true ;
                }else cout << 'B' ;
            }
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
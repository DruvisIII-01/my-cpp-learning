#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ; 
    vector<int> b(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        b[t] = a[t] ;
    }

    for(int t = 1 ; t < n ; ++t) {
        if(b[t] <= b[t + 1]){
            b[t + 1] = b[t + 1] - b[t] ;  
            b[t] = 0 ;
        }else{
            cout << "NO" ;
            return ;
        }
    }cout << "YES" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    int sum = 0 ; 
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        sum += a[t] ;
    }

    //special judge
    bool impossible = true ;
    for(int t = 1 ; t <= n ; ++t) {
        if(a[t] > 1){
            impossible = false ;
            break ; 
        }
    }if(impossible){
        cout << "-1" ;
        return ;
    }

    bool mid = false ;
    for(int t = 2 ; t < n ; ++t) {
        if(a[t] > 1){
            mid = true ; 
            break ; 
        }
    }if(mid){
        cout << sum - 1 ;
        return ;
    }cout << a[1] + a[n] - 1 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
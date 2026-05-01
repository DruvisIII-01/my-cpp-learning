#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ; 
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    int tp = 1 ;
    for(int i = n ; i >= 2 ; i--) {
        if(a[i] > a[i - 1]) {
            tp = i ; 
            break ;
        }
    }
    int pt = 1 ;
    for(int i = tp ; i >= 2 ; i--) {
        if(a[i] < a[i - 1]) {
            pt = i ;
            break ;
        }
    }
    cout << pt - 1 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
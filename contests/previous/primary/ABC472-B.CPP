#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n ; cin >> n ;
    vector<int> l(n + 1) ;
    int sum = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        cin >> l[i] ;
        sum += l[i] ;
    }

    int mi = 2000000 ;
    int cur = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        cur += l[i] ;
        mi = min(mi, abs(2 * cur - sum)) ;
    }cout << mi ; 
    return 0;
}
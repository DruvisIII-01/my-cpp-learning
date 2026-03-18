#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n ; cin >> n ;
    vector <int> x(n), y(n) ;
    for(int i = 0 ; i < n ; i++) cin >> x[i] >> y[i] ;
    
    int B = 2e7 / sqrt(n) ;

    vector <int> ord(n) ;
    for(int i = 0 ; i < n ; i++) ord[i] = i ;
    sort(ord.begin(), ord.end(), 
    [&](int i, int j){
        if(x[i] / B != x[j] / B) return x[i] < x[j] ;
        if((x[i] / B) % 2) return y[i] > y[j] ;
        return y[i] < y[j] ; 
    }) ;

    int start = 0 ;
    while(ord[start] != 0) start++ ;
    rotate(begin(ord), begin(ord) + start, end(ord)) ;
    for(int i = 0 ; i < n ; i++) cout << ord[i] + 1 << " \n"[i + 1 == n] ;
    return 0;
}
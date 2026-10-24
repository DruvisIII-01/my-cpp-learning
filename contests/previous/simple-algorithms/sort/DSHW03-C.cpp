#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int k ; cin >> k ;
    int t ; vector<int> a ;  
    while(cin >> t) a.push_back(t) ;
    sort(a.begin(), a.end(), greater<int>()) ;
    cout << a[k - 1] ;
    return 0;
}
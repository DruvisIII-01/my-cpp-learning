#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    vector <int> hsh(1111) ;
    bool ok = true ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        hsh[a[i]]++ ;
        if(hsh[a[i]] >= 2) ok = false ;
    }
    if(!ok) {
        cout << '-' << '1' ;
        return ;
    }sort(a.begin() + 1, a.begin() + n + 1, greater<int>()) ;
    for(int i = 1 ; i <= n ; i++) cout << a[i] << ' ' ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
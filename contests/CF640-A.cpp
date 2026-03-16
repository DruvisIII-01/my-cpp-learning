#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    int base = 1 ;
    vector <int> ans ;
    do{
        int c = n%10 ;
        if(c != 0) ans.push_back(c*base) ;
        n = n/10 ;
        base = base*10 ;
    }while(n != 0) ;
    cout << ans.size() << endl ;
    for(auto x : ans) cout << x << ' ' ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
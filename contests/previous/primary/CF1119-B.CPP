#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    vector <int> cnt(3) ;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i] ;
        if(a[i] % 2) cnt[0]++ ;
        else if(a[i] % 4 == 2) cnt[1]++ ;
        else cnt[2]++ ;
    }
    int ans = 0 ; 
    for(int i : cnt) ans = max(ans, i) ;
    cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
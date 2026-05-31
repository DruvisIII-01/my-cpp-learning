#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    int cnt1 = 0 ;
    int cnt2 = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
        cnt1 += (a[i] == 1) ;
        cnt2 += (a[i] == 2) ;
    }
    if(cnt1 % 2 == 0 && cnt2 % 2 == 0) cout << "YES" ;
    else if(cnt1 % 2 == 0 && cnt2 % 2 == 1){
        if(cnt1 > 0) cout << "YES" ;
        else cout << "NO" ;
    }else cout << "NO" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
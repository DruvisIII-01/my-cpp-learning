#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ; 
    vector <int> x ;
    vector <int> cnt(n) ;
    //vector <int> pre(n) ;
    map <int, int> hsh ;
    for(int t = 1 ; t <= n ; t++) {
        int x0 = -1 ; cin >> x0 ;
        x.push_back(x0) ;
        hsh[x0]++ ;
    }
    for(int t = 1 ; t <= n ; t++) {
        int y0 = -1 ; cin >> y0 ;
    }
    
    sort(x.begin(), x.end()) ;
    cnt[0] = n ;
    for(int i = 1 ; i < n ; i++) {
        if(x[i] == x[i - 1]) cnt[i] = cnt[i - 1] ;
        else cnt[i] = cnt[i - 1] - hsh[x[i - 1]] ;
    }
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
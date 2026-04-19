#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> b(n + 1) ;
    vector<int> hsh(n + 1) ;
    vector<int> a ;
    vector<int> cnt(n + 1) ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> b[i] ;
        hsh[b[i]] = 1 ;
        if(i == 1 || b[i] != b[i - 1]) a.push_back(b[i]) ;  
    }
    // for(auto x : a) cout << x << ' ' ;
    // cout << endl ;

    int sz = a.size() ;
    //cout << sz << endl ;
    if(sz == 1) {
        cout << 0 ;
        return ;
    }for(int i = 0 ; i < sz ; i++) {
        cnt[a[i]]++ ;
    }for(int i = 1 ; i <= n ; i++) {
        if(!hsh[i]) continue ;
        cnt[i]++ ;
        if(a[0] == i) cnt[i]-- ;
        if(a[sz - 1] == i) cnt[i]-- ;
    }int mi = 1e9 + 114514 ;
    for(int i = 1 ; i <= n ; i++){
        if(!hsh[i]) continue ;
        mi = min(mi, cnt[i]) ;
    }cout << mi ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
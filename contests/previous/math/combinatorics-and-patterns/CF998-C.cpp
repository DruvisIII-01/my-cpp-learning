#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ; 
    vector<int> a(n + 1) ;
    map<int, int> cnt ;
    vector<int> vis ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        if(!cnt[a[t]]) vis.push_back(a[t]) ;
        cnt[a[t]]++ ;
    }
    int same = 0, diff = 0 ;
    for(int x : vis){
        if(x + x == k) same += cnt[x] / 2 ;
        else diff += min(cnt[x], cnt[k - x]) ;
    }cout << same + diff / 2 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
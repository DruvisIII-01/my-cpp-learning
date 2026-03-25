#include <bits/stdc++.h>
using namespace std ;

//#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    vector <int> a(n + 1) ;
    map <int, int> hsh ;
    map <int, bool> ap ;
    vector <int> res ;
    //pair <int> pii ;
    vector <pair<int, int>> ans ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
        hsh[a[i]]++ ;
        if(hsh[a[i]] >= k) {
            if(!ap[a[i]]) {
                ap[a[i]] = 1 ;
                res.push_back(a[i]) ;
            }
        }
    }
    if(res.empty()) {
        cout << '-' << 1 ;
        return ;
    }
    sort(res.begin(), res.end()) ;
    //for(auto x : res) cout << x << ' ' ;
    //cout << endl ;
    int sz = (int) res.size() ;
    if(sz == 1){
        cout << res[0] << ' ' << res[0] ;
        return ;
    }
    int left = 0, right = 0 ;
    for(int i = 1 ; i < sz ; i++){
        if(res[i] >= res[i - 1] + 2){
            ans.push_back({res[left], res[right]}) ;
            left = i ;
            right = i ;
        }
        else if(res[i] == res[i - 1] + 1){
            right = i ;
            if(i == sz - 1) ans.push_back({res[left], res[right]}) ;
        }
    }
    if(ans.empty()) {
        cout << '-' << 1 ;
        return ;
    }
    int mx = -1, ml = -1, mr = -1 ;
    for(auto pii : ans){
        int d = pii.second - pii.first ;
        if(d > mx) {
            mx = d ;
            ml = pii.first ;
            mr = pii.second ;
        }
    }
    cout << ml << ' ' << mr ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
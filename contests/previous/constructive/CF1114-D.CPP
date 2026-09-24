#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> b(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> b[i] ;
    
    vector<int> c(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) c[i] = b[i] ;
    sort(c.begin() + 1, c.end()) ;
    // for(int i = 1 ; i <= n ; ++i) cout << c[i] << ' ' ;
    // cout << endl ;
    vector<int> d ;
    for(int i = 1 ; i <= n ; ++i)
    if(d.empty() || d[d.size() - 1] != c[i]) d.push_back(c[i]) ;
    int diff = d.size() ;
    // for(int i = 0 ; i < diff ; ++i) cout << d[i] << ' ' ;
    // cout << endl ;

    map<int, int> cnt ;
    int mi = LLONG_MAX - 11111 ;
    for(int i = 1 ; i <= n ; ++i) {
        cnt[b[i]]++ ;
        mi = min(mi, b[i]) ;
    }if(mi >= 1){
        cout << "-1" ;
        return ;
    }

    map<int, int> map_to_a ;
    int mx = 0 ; 
    for(int i = 0 ; i < diff - 1 ; i++){
        int tmp = d[i + 1] - d[i] ;
        if(tmp % cnt[d[i]] != 0){
            cout << "-1" ;
            return ;
        }
        if(tmp / cnt[d[i]] > mx) {
            mx = tmp / cnt[d[i]] ;
            map_to_a[d[i]] = mx ;
        }else{
            cout << "-1" ;
            return ;
        }
    }
    if(diff >= 2) map_to_a[d[diff - 1]] = map_to_a[d[diff - 2]] + 1 ;
    else if(!d[0]) map_to_a[d[0]] = 1 ;
    else {
        cout << "-1" ;
        return ;
    }

    for(int i = 1 ; i <= n ; ++i) cout << map_to_a[b[i]] << ' ' ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 224524 ;
int a[MAXN], b[MAXN], c[MAXN], n, k ;

bool check(int reach){
    int cost = 0 ;
    for(int t = 1 ; t <= n ; ++t){
        int cur = a[t] + b[t] + c[t] ;
        if(cur < reach){
            if(a[t] == b[t] && b[t] == c[t]) return false ;
            else if(a[t] <= b[t] && b[t] <= c[t]){
                int minus = 1 + min(abs(c[t] - b[t]), abs(b[t] - a[t])) ;
                cost += (minus * 2) + (reach - cur) ;
            }
            else cost += reach - cur ;
        }if (cost > k) return false; 
    }return cost <= k ;
}

void solve(){
    cin >> n >> k ; 
    int mi = __LONG_LONG_MAX__ ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] >> b[t] >> c[t] ;
        mi = min(mi, a[t] + b[t] + c[t]) ;
    }
    int left = mi, right = mi + 1 + k ;
    while(left + 1 != right){
        int mid = (left + right) / 2 ;
        if(check(mid)) left = mid ;
        else right = mid ;
    } cout << left ;
    for(int t = 1 ; t <= n ; ++t) a[t] = b[t] = c[t] = 0 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
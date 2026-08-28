#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, x ; cin >> n >> x ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    sort(a.begin() + 1, a.begin() + n + 1) ;

    vector<int> sum(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) sum[t] = sum[t - 1] + a[t] ;
    // int mx = -1 ;
    // for(int t = 1 ; t <= n ; ++t) mx = max(a[t], mx) ;

    int left = -1, right = n + 1 ;
    while(left + 1 != right){
        int mid = (left + right) / 2 ;
        int water = a[mid] * mid - sum[mid] ;
        if(water >= x) right = mid ;
        else left = mid ;
    }

    // cout << right << ' ' ;
    int rest = x - ((right - 1) * a[right - 1] - sum[right - 1]) ;
    // cout << rest << ' ' ;
    cout << a[right - 1] + rest / (right - 1) ;
} 

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
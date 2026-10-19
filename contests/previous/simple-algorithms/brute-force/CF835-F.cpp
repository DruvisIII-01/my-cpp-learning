#include <bits/stdc++.h>
using namespace std ;

#define int long long
void P(vector<int>&a){
    cout << "===========" << endl ;
    for(int i = 1 ; i < a.size() ; ++i) cout << a[i] << ' ' ;
    cout << endl << "===========" << endl ;
}

void solve(){
    int n, c, d ; cin >> n >> c >> d ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; t++) cin >> a[t] ;

    sort(a.begin() + 1, a.end(), greater<int>()) ;
    vector<int> pre(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) pre[t] = pre[t - 1] + a[t] ;
    // P(a) ;
    // P(pre) ;

    //special-judge
    if(a[1] * d < c){
        cout << "Impossible" ;
        return ;
    }if(pre[min(n, d)] >= c){
        cout << "Infinity" ;
        return ;
    }

    int ans = -1 ;
    for(int k = d - 1 ; k >= 0 ; k--){
        int one = pre[min(k + 1, n)] ;
        int turns = d / (k + 1), rest = d % (k + 1) ;
        int coins = one * turns + pre[min(rest, n)] ;
        if(coins >= c){
            ans = k ;
            break ;
        }
    }cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
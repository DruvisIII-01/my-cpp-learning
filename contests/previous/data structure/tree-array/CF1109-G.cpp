#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
    vector<int> dp(n + 1) ;
    vector<int> tree(n + 1) ;
    vector<vector<pair<int, int>>> lst(n + 1) ;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j < lst[i].size() ; ++j){
            int idx = lst[i][j].first ;
            int val = lst[i][j].second ;
            for(int x = idx ; x <= n ; x += (x & (-x))){
                tree[x] = max(tree[x], val) ;
            }
        }
        int res = 0 ;
        for(int x = i - a[i] - 1 ; x > 0 ; x -= (x & (-x))){
            res = max(tree[x], res) ;
        }dp[i] = res + a[i] ;
        int t = i + a[i] + 1 ;
        if(t <= n) lst[t].push_back(make_pair(i, dp[i])) ;
    }
    int ans = -1 ;
    for(int i = 1 ; i <= n ; i++) ans = max(dp[i], ans) ;
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
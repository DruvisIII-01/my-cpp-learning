#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    sort(a.begin() + 1, a.end()) ;
    int mx = a[n] ;

    vector<int> cons(n + 1) ; 
    for(int t = 1 ; t <= n ; ++t) {
        if(t & 1) cons[(t + 1) / 2] = a[t] ;
        else cons[n + 1 - t / 2] = a[t] ;  
    }

    vector<int> vis(n + 1) ;
    for(int t = 1 ; t <= n ; t++) {
        if(t == 1) vis[t] = true ;
        else if(cons[t] > cons[t - 1]) vis[t] = true ;
    }
    for(int t = n ; t >= 1 ; t--) {
        if(t == n) vis[t] = true ;
        else if(cons[t] > cons[t + 1]) vis[t] = true ;
    }
    int ans = 0 ;
    for(int t = 1 ; t <= n ; ++t) ans += vis[t] ;
    cout << ans << endl ;
    for(int t = 1 ; t <= n ; ++t) cout << cons[t] << ' ' ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】Books on a Shelf
 * 题目链接：https://codeforces.com/problemset/problem/2290/C
 * 标签：难度 2290C（新场次，暂无 rating） | constructive, greedy, sortings
 *
 * 关键思路：排序后把元素按下标奇偶交替放进两端（小的放中间、大的放两头），形成"先降后升"的山谷形排列，再统计满足"大于左右邻居之一"的局部峰个数。
 * ################################################################## */

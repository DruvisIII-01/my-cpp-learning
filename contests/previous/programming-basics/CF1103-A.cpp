#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    int mx = -1, mi = 10 ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        mx = max(mx, a[t]) ;
        mi = min(mi, a[t]) ;
    }cout << mx - mi + 1 ;
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
 * 【题面与关键思路】Games on the Train
 * 题目链接：https://codeforces.com/problemset/problem/2236/A
 * 标签：难度 800 | greedy, math
 *
 * 关键思路：答案是 max(a) − min(a) + 1，求极差即可。
 * ################################################################## */

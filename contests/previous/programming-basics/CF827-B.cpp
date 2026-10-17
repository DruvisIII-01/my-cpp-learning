#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    map<int, bool> vis ;
    bool ans = true ;
    for(int t = 1 ; t <= n ; ++t){
        cin >> a[t] ;
        if(vis[a[t]]) ans = false ;
        else vis[a[t]] = true ;
    }
    if(ans) cout << "YES" ;
    else cout << "NO" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
/* ######################################################################
 * 【题面与关键思路】Increasing
 * 题目链接：https://codeforces.com/problemset/problem/1742/B
 * 标签：难度 800 | implementation, sortings
 *
 * 关键思路：用 map/set 判重：出现重复元素则 NO（因为排列中去重后无法严格递增），否则 YES。
 * ###################################################################### */

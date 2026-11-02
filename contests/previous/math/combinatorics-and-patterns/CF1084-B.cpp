#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    bool ans = true ;
    for(int t = 2 ; t <= n ; ++t){
        if(a[t] < a[t - 1]){
            ans = false ;
            break ;
        }
    }
    if(ans) cout << n ;
    else cout << 1 ;
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
 * 【题面与关键思路】Deletion Sort
 * 题目链接：https://codeforces.com/problemset/problem/2200/B
 * 标签：难度 800 | bitmasks, brute force, greedy, sortings
 *
 * 关键思路：若数组本来非降序则输出 n（一个都不用删），否则输出 1。
 * ################################################################## */

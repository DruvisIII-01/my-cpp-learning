#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    int mx = -1 ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        mx = max(mx, a[t]) ;
    } 
    int ans = 0 ;
    for(int t = 1 ; t <= n ; ++t){
        ans += (mx == a[t]) ;
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

/* ##################################################################
 * 【题面与关键思路】Eating Game
 * 题目链接：https://codeforces.com/problemset/problem/2200/A
 * 标签：难度 800 | greedy
 *
 * 关键思路：统计有多少个元素等于最大值，直接输出个数。
 * ################################################################## */

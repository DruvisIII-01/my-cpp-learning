#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
    int ans = 0, cnt0 = 0, cnt1 = 0, cnt2 = 0 ;
    for(int i = 1 ; i <= n ; i++){
        cnt0 += (a[i] == 0) ;
        cnt1 += (a[i] == 1) ;
        cnt2 += (a[i] == 2) ;
    }
    int M = max(cnt1, cnt2), m = min(cnt1, cnt2) ;
    ans = cnt0 + m + (M - m) / 3 ;
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

/* ######################################################################
 * 【题面与关键思路】Marisa Steals Reimu's Takeout
 * 题目链接：https://codeforces.com/problemset/problem/2228/A
 * 标签：难度 800 | greedy,implementation
 *
 * 关键思路：统计 0、1、2 的个数：每个 0 单独成组，min(cnt1,cnt2) 对 (1,2) 配对，剩余的同类每 3 个凑一组。
 * ###################################################################### */

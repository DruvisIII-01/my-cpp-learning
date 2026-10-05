#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, c, d ; cin >> a >> b >> c >> d ;
    int ans = (b > a) + (c > a) + (d > a) ;
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
 * 【题面与关键思路】Marathon
 * 题目链接：https://codeforces.com/problemset/problem/1692/A
 * 标签：难度 800 | implementation
 *
 * 关键思路：统计另外三个数中比 a 大的个数。
 * ###################################################################### */

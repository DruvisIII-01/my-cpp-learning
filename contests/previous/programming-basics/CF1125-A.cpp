#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int x, y, r ; cin >> x >> y >> r ;
    cout << x - r << ' ' << y ;
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
 * 【题面与关键思路】In Search of Convenience
 * 题目链接：https://codeforces.com/problemset/problem/2275/A
 * 标签：难度 800 | geometry, implementation
 *
 * 关键思路：输出 (x−r, y)：把圆心左移半径长度。
 * ################################################################## */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int x, y ; cin >> x >> y ;
    int r1 = x % 2, r2 = y % 2 ;
    if(r1 == 1 && r2 == 1) cout << "NO" ;
    else cout << "YES" ;
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
 * 【题面与关键思路】Koshary
 * 题目链接：https://codeforces.com/problemset/problem/2227/A
 * 标签：难度 800 | implementation,math
 *
 * 关键思路：两个数都为奇数则 NO，否则 YES（只要有一个偶数就能均分）。
 * ###################################################################### */

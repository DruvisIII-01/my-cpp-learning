#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b ; cin >> a >> b ;
    cout << b - a ;
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
 * 【题面与关键思路】Minimize!
 * 题目链接：https://codeforces.com/problemset/problem/2009/A
 * 标签：难度 800 | brute force,math
 *
 * 关键思路：答案 = b - a。
 * ###################################################################### */

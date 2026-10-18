#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int x, y ; cin >> x >> y ;
    if(x % y == 0) cout << "YES" ;
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
 * 【题面与关键思路】Divide and Conquer
 * 题目链接：https://codeforces.com/problemset/problem/2241/A
 * 标签：难度 800 | greedy,math,number theory
 *
 * 关键思路：每次操作把 x 除以一个 z，设这些 z 的乘积为 P，则 y = x/P，故 P = x/y 必须是整数 —— 即 x 能被 y 整除时输出 YES，否则 NO。
 * ###################################################################### */

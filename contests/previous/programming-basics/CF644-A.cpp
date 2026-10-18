#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b ; cin >> a >> b ;
    int ans = min(
        max(a, b + b), max(b, a + a) 
    ) ; cout << ans * ans ;
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
 * 【题面与关键思路】Minimal Square
 * 题目链接：https://codeforces.com/problemset/problem/1360/A
 * 标签：难度 800 | greedy,math
 *
 * 关键思路：两个 a×b 矩形拼正方形，边长只可能是 max(a, 2b) 或 max(b, 2a)，取较小者再平方。
 * ###################################################################### */

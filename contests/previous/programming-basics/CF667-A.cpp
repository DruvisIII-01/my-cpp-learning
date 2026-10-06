#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b ; cin >> a >> b ;
    cout << (abs(a - b) + 9) / 10 ;
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
 * 【题面与关键思路】Yet Another Two Integers Problem
 * 题目链接：https://codeforces.com/problemset/problem/1409/A
 * 标签：难度 800 | greedy, math
 *
 * 关键思路：每次最多改变 10，答案 = ceil(|a-b|/10)。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n; cin >> n;
    for(int i = n; i >= 1; i--) cout << i << ' ';
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
 * 【题面与关键思路】A Simple Sequence
 * 题目链接：https://codeforces.com/problemset/problem/2210/A
 * 标签：难度 800 | constructive algorithms,dp,greedy,number theory
 *
 * 关键思路：直接把 1..n 逆序输出即可满足任意相邻 1 的个数不超过 k 的条件。
 * ###################################################################### */

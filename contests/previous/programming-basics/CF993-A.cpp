#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; cout << n - 1 ;
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
 * 【题面与关键思路】Easy Problem
 * 题目链接：https://codeforces.com/problemset/problem/2044/A
 * 标签：难度 800 | brute force,math
 *
 * 关键思路：n 个人分 n 个座位，两两不能相邻坐，最少要空出多少座位：答案直接是 n − 1（除第 1 人外每人预留一个空位）。
 * ###################################################################### */

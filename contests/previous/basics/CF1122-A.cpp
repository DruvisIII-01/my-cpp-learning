#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    int a, b, c ; cin >> a >> b >> c ;
    cout << n - min(min(a, b), c) ;
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
 * 【题面与关键思路】Good Contest
 * 题目链接：https://codeforces.com/problemset/problem/2266/A
 * 标签：难度 800 | greedy
 *
 * 关键思路：答案即 n - min(a, b, c)：选出现人数最少的那类题即可。
 * ###################################################################### */

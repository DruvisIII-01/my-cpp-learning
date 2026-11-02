#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, c ; cin >> a >> b >> c ;
    cout << a + b + c - min(min(a, b), c) - max(a, max(b, c)) ;
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
 * 【题面与关键思路】Medium Number
 * 题目链接：https://codeforces.com/problemset/problem/1760/A
 * 标签：难度 800 | implementation, sortings
 *
 * 关键思路：三个数里取中位数：`a+b+c - min - max`。
 * ################################################################## */

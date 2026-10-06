#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    string s ; cin >> s ;
    int a = s[0] - '0' + s[1] - '0' + s[2] - '0' ;
    int b = s[3] - '0' + s[4] - '0' + s[5] - '0' ;
    if(a == b) cout << "YES" ;
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
 * 【题面与关键思路】Lucky?
 * 题目链接：https://codeforces.com/problemset/problem/1676/A
 * 标签：难度 800 | implementation
 *
 * 关键思路：比较六位票号前三位的数字和与后三位是否相等。
 * ###################################################################### */

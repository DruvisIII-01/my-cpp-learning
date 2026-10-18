#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    string s ; cin >> s ;
    if(s[0] == 'a' || s[1] == 'b' || s[2] == 'c') cout << "YES" ;
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
 * 【题面与关键思路】Short Sort
 * 题目链接：https://codeforces.com/problemset/problem/1873/A
 * 标签：难度 800 | brute force,implementation
 *
 * 关键思路：判断首位是否为 a、次位是否为 b、末位是否为 c，任一满足即 YES。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, c ; cin >> a >> b >> c ;
    if(a + b == c || a + c == b || a == c + b) cout << "YES" ;
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
 * 【题面与关键思路】Sum
 * 题目链接：https://codeforces.com/problemset/problem/1742/A
 * 标签：难度 800 | implementation
 *
 * 关键思路：判断三个数中是否有一个等于另外两个之和，三种情况分别判断即可。
 * ###################################################################### */

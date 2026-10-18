#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, c, d ; cin >> a >> b >> c >> d ;
    if(a == b && b == c && c == d){
        cout << "YES" ;
    }else cout << "NO" ;
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
 * 【题面与关键思路】Draw a Square
 * 题目链接：https://codeforces.com/problemset/problem/2074/A
 * 标签：难度 800 | geometry,implementation
 *
 * 关键思路：判断四点是否构成正方形（只需检查四数是否全部相等或满足边长关系），直接输出 YES/NO。
 * ###################################################################### */

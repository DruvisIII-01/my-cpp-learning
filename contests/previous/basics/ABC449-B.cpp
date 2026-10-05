#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int h, w, q ; cin >> h >> w >> q ;
    while(q--){
        int op, delta ; cin >> op >> delta ;
        if(op == 1){
            cout << delta * w << endl ;
            h -= delta ;
        }else {
            cout << delta * h << endl ;
            w -= delta ;
        }
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Deconstruct Chocolate
 * 题目链接：https://atcoder.jp/contests/abc449/tasks/abc449_b
 * 标签：难度 ABC B
 *
 * 关键思路：维护剩余的 h、w，每次切一行贡献 delta*w（或一列贡献 delta*h），逐次更新即可。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n ; cin >> n ;
    bool is_ok = true ;
    for(int i = 1 ; i <= n ; ++i){
        int order ; cin >> order ;
        if(order > (i + 9) / 10 * 10) {
            is_ok = false ;
            break ;
        }
    }if(is_ok) cout << "Yes" ;
    else cout << "No" ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Exit Order
 * 题目链接：https://atcoder.jp/contests/abc474/tasks/abc474_b
 * 标签：难度 ABC B | 模拟
 *
 * 关键思路：逐人检查其序号是否超过"当前十位档位的上界"，出现违规即 No。
 * ###################################################################### */

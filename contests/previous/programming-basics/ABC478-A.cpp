#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n, m ; cin >> n >> m ;
    int ans = m / n ;
    int rest = m % n ;

    for(int i = 1 ; i <= n ; ++i){
        if(i <= rest) cout << ans + 1 << '\n' ;
        else cout << ans << '\n' ;
    }

    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Grapes
 * 题目链接：https://atcoder.jp/contests/abc478/tasks/abc478_a
 * 标签：难度 ABC A | 语法/取整
 *
 * 关键思路：把 m 个葡萄尽量平均分给 n 个人：先算 ans = m/n、rest = m%n，前 rest 个人拿 ans+1，其余拿 ans。
 * ###################################################################### */

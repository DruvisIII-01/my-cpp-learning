#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int x, y ; cin >> x >> y ;
    if(x == 0 && y != 0) cout << (y + 1) / 2 ;
    else if(x != 0 && y == 0) cout << (x + 14) / 15 ;
    else if(x == 0 && y == 0) cout << 0 ;
    else{
        int cnt2 = (y + 1) / 2 ;
        int rest = 0 ;
        if(y % 2 == 0) rest = x - cnt2 * 7 ;
        else rest = x - (cnt2 - 1) * 7 - 11 ;
        if(rest <= 0) cout << cnt2 ;
        else cout << cnt2 + (rest + 14) / 15 ;
    }
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
 * 【题面与关键思路】Stickogon
 * 题目链接：https://codeforces.com/problemset/problem/1957/A
 * 标签：难度 800 | constructive algorithms, greedy
 *
 * 关键思路：用 2x2 与 1x1 拼 n 个直角多边形：答案是按奇偶分类讨论 y 需要多少 2x2 块、剩余 x 是否够填的向上取整。
 * ###################################################################### */

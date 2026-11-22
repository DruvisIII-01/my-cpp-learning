#include <bits/stdc++.h>
using namespace std ;

#define int long long

void _print(int time, char ch){
    for(int t = 1 ; t <= time ; ++t) cout << ch ;
}

void solve(){
    int x, y, z ; cin >> x >> y >> z ;
    if(x >= max(y, z)) _print(x + y + z, 'P') ;
    else if(y >= max(z, x)) _print(x + y + z, 'R') ;
    else if(z >= max(x, y)) _print(x + y + z, 'S') ;
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
 * 【题面与关键思路】Stakes and Shapes
 * 题目链接：https://codeforces.com/problemset/problem/2278/B
 * 标签：难度 2278B（新场次，暂无 rating） | constructive, greedy
 *
 * 关键思路：石头剪刀布：某种手势数量不小于另外两种之和时，全部出这种手势就能通吃，长度取 x+y+z 全填同一字符。
 * ################################################################## */

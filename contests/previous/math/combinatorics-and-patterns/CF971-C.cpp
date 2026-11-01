#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int x, y, k ; cin >> x >> y >> k ;
    int sx = (x + k - 1) / k, sy = (y + k - 1) / k ;
    if(sx > sy) cout << 2 * sx - 1 ;
    else cout << 2 * sy ;
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
 * 【题面与关键思路】The Legend of Freya the Frog
 * 题目链接：https://codeforces.com/problemset/problem/2009/C
 * 标签：难度 1100 | implementation,math
 *
 * 关键思路：每次跳跃可覆盖 0..k 的位移，分别算 x、y 方向所需步数 ceil(x/k) 与 ceil(y/k)，交替跳跃取 2*sy 或 2*sx-1。
 * ###################################################################### */

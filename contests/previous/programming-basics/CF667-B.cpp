#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, x, y, n ; cin >> a >> b >> x >> y >> n ;
    int da = a - x, db = b - y ;
    if(da + db <= n) cout << x * y ;
    else{
        int up = min(n, a - x) ;
        int down = max((int)0, n + y - b) ;
        int ans1 = (a - down) * (b - n + down) ;
        int ans2 = (a - up) * (b - n + up) ;
        cout << min(ans1, ans2) ; 
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
 * 【题面与关键思路】Minimum Product
 * 题目链接：https://codeforces.com/problemset/problem/1409/B
 * 标签：难度 1100 | brute force,greedy,math
 *
 * 关键思路：只可能先把 a 降到 x、或先把 b 降到 y，两种顺序各算一次取最小乘积（注意下界不能为负）。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    int ans1 = 0 ;
    int ans2 = 0 ;
    int ans3 = 0 ;
    for(int i = 1 ; i <= n ; ++i) {
        int T = (a[i] + 999) / 1000 ;
        int change = T * 1000 - a[i] ;
        //cout << change << endl ;
        
        ans3 += change / 100 ; 
        change %= 100 ;
        ans2 += change / 10 ;
        change %= 10 ;
        ans1 += change ;
    }
    cout << ans1 << ' ' << ans2 << ' ' << ans3 ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Change
 * 题目链接：https://atcoder.jp/contests/abc475/tasks/abc475_b
 * 标签：难度 ABC B | 模拟, 贪心
 *
 * 关键思路：把金额补到 1000 的整数倍，再用 500/100/50/10/5/1 面额贪心找零，统计硬币数。
 * ###################################################################### */

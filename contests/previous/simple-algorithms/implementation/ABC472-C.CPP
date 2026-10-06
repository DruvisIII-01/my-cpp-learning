#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int n, m, k ; cin >> n >> m >> k ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    vector<bool> vis(n + 1) ;
    int cur = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        if(cur + a[i] <= k) {
            cur += a[i] ;
            vis[i] = true ; 
            cout << "Yes" << endl ;
        }else cout << "No" << endl ;
        if(i - m + 1 >= 1){
            if(vis[i - m + 1]){
                cur -= a[i - m + 1] ;
                vis[i - m + 1] = false ;
            }
        }
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】On a Diet 节食
 * 题目链接：https://atcoder.jp/contests/abc472/tasks/abc472_c
 * 标签：难度 ABC C | 滑动窗口
 *
 * 关键思路：维护长度不超过 m 的滑动窗口内的和：能放就放并输出 Yes，超出窗口范围就把它从和中减去。
 * ###################################################################### */

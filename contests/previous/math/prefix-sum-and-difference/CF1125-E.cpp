#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    vector<int> b(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    for(int t = 1 ; t <= n ; ++t) cin >> b[t] ;
    if(n == 1){
        cout << 2 - (a[n] != b[n]) ;
        return ;
    }

    vector<int> pre1(n + 1) ;
    vector<int> pre2(n + 1) ; 
    vector<int> suf(n + 2) ;
    for(int t = 1 ; t < n ; ++t)
    pre1[t] = pre1[t - 1] + 2 - (a[t] != b[t]) ;
    pre1[n] = pre1[n - 1] ;
    for(int t = 1 ; t < n ; ++t)
    pre2[t] = pre2[t - 1] + 2 - (b[t] != a[t + 1]) ;
    pre2[n] = pre2[n - 1] ;
    for(int t = n - 1 ; t >= 1 ; t--)
    suf[t] = suf[t + 1] + 4 
    - (a[t] != b[t + 1]) - (b[t] != a[t + 1]) ;

    int ans = LONG_LONG_MIN, N = 2 - (a[n] != b[n]) ;
    for(int t = 0 ; t <= n ; ++t) {
        int val = pre1[t] + pre2[t] + suf[t + 1] + N ;
        //cout << val << endl ;
        ans = max(ans, val) ;
    }
    cout << ans ;
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
 * 【题面与关键思路】Repentance Is Already on the Way
 * 题目链接：https://codeforces.com/problemset/problem/2275/E
 * 标签：难度 1500 | dp, implementation
 *
 * 关键思路：预处理三种前缀/后缀贡献（a 与 b 相同、b 与 a 错位、以及后缀交叉），枚举分割点 t 取四段之和的最大值。
 * ################################################################## */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a[7] ;
    for(int i = 0 ; i <= 6 ; i++) cin >> a[i] ;
    sort(a, a+7) ;
    a[6] = -a[6] ;
    int ans = 0 ;
    for(int i = 0 ; i <= 6 ; i++) ans -= a[i] ;
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

/* ######################################################################
 * 【题面与关键思路】The 67th 6-7 Integer Problem
 * 题目链接：https://codeforces.com/problemset/problem/2218/B
 * 标签：难度 800 | greedy,math
 *
 * 关键思路：7 个数里选 6 个取相反数，等价于把一个数取正、其余取负；取绝对值最大的数作为"不取反"的那个收益最大。
 * ###################################################################### */

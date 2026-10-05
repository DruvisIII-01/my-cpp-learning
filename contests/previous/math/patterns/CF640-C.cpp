#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    int t1 = k/(n-1), t2 = k%(n-1) ;
    if(t2 == 0) {
        t2 = n-1 ;
        t1-- ;
    }
    cout << t1*n + t2 ;
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
 * 【题面与关键思路】K-th Not Divisible by n
 * 题目链接：https://codeforces.com/problemset/problem/1352/C
 * 标签：难度 1200 | binary search, math
 *
 * 关键思路：每 n-1 个合法数构成一组，k/(n-1) 确定组号、k%(n-1) 确定组内偏移，注意整除时要退一组。
 * ###################################################################### */

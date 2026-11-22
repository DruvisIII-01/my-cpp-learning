#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, c ; cin >> a >> b >> c ; 
    int m = min(a, min(b, c)), M = max(a, max(b, c)) ;
    int Mm = a + b + c - m - M ; 
    if(Mm + 1 == M && m + 1 == Mm) cout << "YES" ;
    else cout << "NO" ;
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
 * 【题面与关键思路】Three Piles
 * 题目链接：https://codeforces.com/problemset/problem/2290/A
 * 标签：难度 2290A（新场次，暂无 rating） | implementation, math
 *
 * 关键思路：排序后判断三个数是否构成连续整数（中间值 +1 等于最大值、最小值 +1 等于中间值），是则 YES。
 * ################################################################## */

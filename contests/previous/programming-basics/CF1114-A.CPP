#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a[3] = {} ; 
    for(int i = 0 ; i < 3 ; ++i) cin >> a[i] ;
    sort(a, a + 3) ;

    //a[0] <= a[1] <= a[2]
    int ans1 = min(a[1] - a[0], a[2] - a[1]) ;
    int ans2 = 222 ;
    if((a[2] - a[0]) % 2 == 0) ans2 = (a[2] - a[0]) / 2 ;
    cout << min(ans1, ans2) ;
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
 * 【题面与关键思路】Riptide
 * 题目链接：https://codeforces.com/problemset/problem/2254/A
 * 标签：难度 800 | implementation,sortings
 *
 * 关键思路：三个数排序后取"两两差的较小值"，答案由分类讨论得到。
 * ###################################################################### */

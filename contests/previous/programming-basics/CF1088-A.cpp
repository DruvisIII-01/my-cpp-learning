#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    for(int i = 1 ; i <= n ; i++) {
        int x ; cin >> x ;
    }
    if(n == 1) {
        cout << 1 ;
        return ;
    }
    for(int i = 1 ; i <= n ; i++){
        cout << 2 << ' ' ;
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
 * 【题面与关键思路】Antimedian Deletion
 * 题目链接：https://codeforces.com/problemset/problem/2211/A
 * 标签：难度 800 | implementation,math
 *
 * 关键思路：观察结论：n 为偶数时输出 (n, 2) 之类的一对，奇数时输出 (n-1, 2)，恒可用常数对构造答案。
 * ###################################################################### */

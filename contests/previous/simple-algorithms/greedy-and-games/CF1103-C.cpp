#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, x ; cin >> a >> b >> x ;
    int tmp1 = a, tmp2 = b ;
    int ans = min(abs(a - b), (int)61) ;
    for(int i = 0 ; i < 30 ; ++i){
        if(i) tmp1 /= x ;
        tmp2 = b ;
        for(int j = 0 ; j < 30 ; ++j){
            //if(!tmp2) break ;
            if(j) tmp2 /= x ;
            ans = min(abs(tmp1 - tmp2) + i + j, ans) ;
        }
    }cout << ans ;
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
 * 【题面与关键思路】Omsk Programmers
 * 题目链接：https://codeforces.com/problemset/problem/2236/C
 * 标签：难度 1000 | brute force, greedy, math
 *
 * 关键思路：枚举两边各除以 x 的次数 i、j（≤ 30 次），取 |a/x^i − b/x^j| + i + j 的最小值。
 * ################################################################## */

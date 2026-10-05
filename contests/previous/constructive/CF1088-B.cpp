#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 676767677 ;

void solve(){
    int x, y ; cin >> x >> y ;
    int n = abs(x - y), ans = 0 ;
    if(n == 0){
        cout << 1 << endl ;
        for(int i = 1 ; i <= x ; i++) cout << 1 << ' ' ;
        for(int i = 1 ; i <= y ; i++) cout << '-' << 1 << ' ' ;
        return ;
    }
    for(int i = 1 ; i * i <= n ; i++){
        if(n % i == 0) {
            ans++ ;
            int ai = n / i ;
            if(ai != i && n % ai == 0) ans++ ;
        } 
    }cout << ans << endl ;
    for(int i = 1 ; i <= x ; i++) cout << 1 << ' ' ;
    for(int i = 1 ; i <= y ; i++) cout << '-' << 1 << ' ' ;
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
 * 【题面与关键思路】Mickey Mouse Constructive
 * 题目链接：https://codeforces.com/problemset/problem/2211/B
 * 标签：难度 1100 | constructive algorithms, dp, greedy, math
 *
 * 关键思路：构造 x 的约数 d 使 x/d = y：需要 d | x 且 (x/d) = y，即枚举 x 的约数判定；数论构造 + 试除。
 * ###################################################################### */

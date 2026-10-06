#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    vector <int> b(n + 1) ;
    int mi_a = 1e9, mi_b = 1e9 ; 
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
        mi_a = min(mi_a, a[i]) ;
    }
    for(int i = 1 ; i <= n ; i++) {
        cin >> b[i] ;
        mi_b = min(mi_b, b[i]) ;
    }
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        ans += max(
            a[i] - mi_a, b[i] - mi_b 
        ) ;
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

/* ######################################################################
 * 【题面与关键思路】Gifts Fixing
 * 题目链接：https://codeforces.com/problemset/problem/1399/B
 * 标签：难度 800 | greedy
 *
 * 关键思路：记录 a、b 各自的最小值，每对 (a[i],b[i]) 需降到最小值，一次操作可同时减两者，故代价为 max(a[i]-mina, b[i]-minb) 之和。
 * ###################################################################### */

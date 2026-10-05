#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ; 
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    int mx = 1, cur = 1 ;
    for(int i = 2 ; i <= n ; i++) {
        if(a[i] == a[i - 1]) {
            cur++ ;
            if(i == n) mx = max(cur, mx) ;
        }else{
            mx = max(mx, cur) ;
            cur = 1 ; 
        }
    }if(mx >= m) cout << "NO" ;
    else cout << "YES" ;
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
 * 【题面与关键思路】OIE Excursion
 * 题目链接：https://codeforces.com/problemset/problem/2220/B
 * 标签：难度 1200 | greedy
 *
 * 关键思路：检查是否存在长度 >= m 的连续相同元素段：有则 NO，否则 YES（本题是"连续段"判定）。
 * ###################################################################### */

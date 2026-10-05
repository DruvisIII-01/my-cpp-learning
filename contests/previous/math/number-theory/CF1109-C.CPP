#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, x, y ; cin >> n >> x >> y ;
    int t = __gcd(x, y) ;

    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    vector <int> mv(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) 
    mv[a[i]] = abs(a[i] - i) ;

    bool ans = true ;
    for(int i = 1 ; i <= n ; ++i){
        if(mv[i] % t != 0){
            ans = false ;
            break ;
        }
    }
    if(ans) cout << "YES" ;
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

/* ######################################################################
 * 【题面与关键思路】Stepan and Permutation
 * 题目链接：https://codeforces.com/problemset/problem/2244/C
 * 标签：难度 1100 | constructive algorithms, dfs and similar, dsu, greedy, math, number theory, sortings
 *
 * 关键思路：交换不改变下标模 gcd(x,y) 的余数：只对同余类内部排序，比较与目标排列是否一致。
 * ###################################################################### */

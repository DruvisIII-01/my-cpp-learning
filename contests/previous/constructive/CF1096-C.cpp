#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    vector <int> b ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    for(int i = 1 ; i <= n ; i++) {
        if(a[i] % 6 == 0) b.push_back(a[i]) ;
    }
    for(int i = 1 ; i <= n ; i++) {
        if(a[i] % 2 == 0 && a[i] % 3 != 0) b.push_back(a[i]) ;
    }
    for(int i = 1 ; i <= n ; i++) {
        if(a[i] % 2 != 0 && a[i] % 3 != 0) b.push_back(a[i]) ;
    }
    for(int i = 1 ; i <= n ; i++) {
        if(a[i] % 2 != 0 && a[i] % 3 == 0) b.push_back(a[i]) ;
    }
    for(auto x : b) cout << x << ' ' ;
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
 * 【题面与关键思路】Snowfall
 * 题目链接：https://codeforces.com/problemset/problem/2227/C
 * 标签：难度 800 | constructive algorithms, math
 *
 * 关键思路：把数按"能被 2 整除/能被 3 整除"分成四类，按固定顺序重新排列，使相邻两数不同时被 2 或同时被 3 整除。
 * ###################################################################### */

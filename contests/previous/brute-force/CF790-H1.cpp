#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        for(int j = 1 ; j < i ; j++){
            ans += (a[j] >= a[i]) ;
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

/* ######################################################################
 * 【题面与关键思路】Maximum Crossings (Easy Version)
 * 题目链接：https://codeforces.com/problemset/problem/1676/H1
 * 标签：难度 1400 | brute force
 *
 * 关键思路：求逆序对（相等的也算），直接 O(n^2) 双重循环枚举数对统计 a[j] >= a[i]；hard 版需树状数组。
 * ###################################################################### */

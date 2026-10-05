#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
    }int ans = -1 ;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = i + 1 ; j <= n ; j++){
            ans = max(ans, a[i]^a[j]) ;
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
 * 【题面与关键思路】The 67th XOR Problem
 * 题目链接：https://codeforces.com/problemset/problem/2218/E
 * 标签：难度 1200 | binary search, bitmasks, brute force
 *
 * 关键思路：求最大 a[i] xor a[j]。规模允许 O(n^2) 双重枚举；也可用按位 Trie 或按位贪心优化。
 * ###################################################################### */

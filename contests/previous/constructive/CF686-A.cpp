#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    for(int i = 1 ; i <= n ; i++) {
        int x = (i + 1 + n) % n ;
        if(x == 0) x = n ;
        cout << x << ' ' ;
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
 * 【题面与关键思路】Special Permutation
 * 题目链接：https://codeforces.com/problemset/problem/1454/A
 * 标签：难度 800 | constructive algorithms,probabilities
 *
 * 关键思路：输出整体左移一位的排列（第 i 位放 i+1，末位放 1），即每个数都不在原来的位置上。
 * ###################################################################### */

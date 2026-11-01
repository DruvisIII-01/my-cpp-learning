#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    //1, 3n-1, 3n, 2, 3n-3, 3, 3n-5, ... , n, 2n,  
    for(int i = 1 ; i <= n ; i++){
        cout << i << ' ' << 3 * n - 2 * i + 1 << ' ' << 3 * n - i * 2+ 2 << ' ' ; 
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
 * 【题面与关键思路】The 67th Permutation Problem
 * 题目链接：https://codeforces.com/problemset/problem/2218/C
 * 标签：难度 800 | constructive algorithms,greedy,math
 *
 * 关键思路：按公式输出：第 i 组输出 i、3n-2i+1、3n-2i+2，使每三个连续数的和相等。
 * ###################################################################### */

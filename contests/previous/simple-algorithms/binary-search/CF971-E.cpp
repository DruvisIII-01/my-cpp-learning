#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    int tt = n * (2 * k + n - 1) / 2 ; 
    int L = 0, R = n + 1 ;
    while(R != L + 1){
        int M = (L + R) >> 1 ; 
        int cp = (2 * k + M - 1) * M ;
        if(cp >= tt) R = M ;
        else L = M ;
    }
    int a1 = abs(tt - L * (2 * k + L - 1)) ;
    int a2 = abs(tt - R * (2 * k + R - 1)) ;
    cout << min(a1, a2) ;
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
 * 【题面与关键思路】Klee's SUPER DUPER LARGE Array!!!
 * 题目链接：https://codeforces.com/problemset/problem/2009/E
 * 标签：难度 1400 | binary search,math,ternary search
 *
 * 关键思路：数组是 k..k+n-1 的等差段，前后两段和的差关于分割点先减后增，二分/三分出零点，比较相邻两项取最小绝对差。
 * ###################################################################### */

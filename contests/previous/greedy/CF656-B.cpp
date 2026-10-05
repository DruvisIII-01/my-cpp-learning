#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ; 
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    int tp = 1 ;
    for(int i = n ; i >= 2 ; i--) {
        if(a[i] > a[i - 1]) {
            tp = i ; 
            break ;
        }
    }
    int pt = 1 ;
    for(int i = tp ; i >= 2 ; i--) {
        if(a[i] < a[i - 1]) {
            pt = i ;
            break ;
        }
    }
    cout << pt - 1 ;
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
 * 【题面与关键思路】Restore the Permutation by Merger
 * 题目链接：https://codeforces.com/problemset/problem/1385/B
 * 标签：难度 800 | greedy
 *
 * 关键思路：先找从右往左第一个上升位置确定后缀起点，再找该点之前最后一个下降位置，答案即该下标减 1。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) {cin >> a[i] ;}
    sort(a.begin() + 1, a.begin() + n + 1) ;
    int mi = 1e9 + 114514 ;
    for(int i = 2 ; i <= n ; i++){
        mi = min(mi, a[i] - a[i - 1]) ;
    }cout << mi ;
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
 * 【题面与关键思路】Honest Coach
 * 题目链接：https://codeforces.com/problemset/problem/1360/B
 * 标签：难度 800 | greedy, sortings
 *
 * 关键思路：排序后取相邻差的最小值，即为两组实力差的最小可能值。
 * ###################################################################### */

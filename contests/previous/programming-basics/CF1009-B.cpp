#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ; 
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
    int sum = 0 ; 
    for(int i = 1 ; i <= n ; ++i) sum += a[i] ;
    cout << sum - (n - 1) ;
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
 * 【题面与关键思路】The Third Side
 * 题目链接：https://codeforces.com/problemset/problem/2074/B
 * 标签：难度 800 | geometry, greedy, math
 *
 * 关键思路：合并操作只能减少 n-1 次，答案 = Σa - (n-1)。
 * ###################################################################### */

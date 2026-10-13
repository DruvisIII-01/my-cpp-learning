#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    vector <int> a(n + 1) ;
    int sum = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
        sum += a[i] ;
    }
    bool win_without = (sum % 2 == 1) ;
    bool win_with = (n * k % 2 == 0) ;
    if(win_without || win_with) cout << "YES" ;
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
 * 【题面与关键思路】The Equalizer
 * 题目链接：https://codeforces.com/problemset/problem/2217/A
 * 标签：难度 800 | math
 *
 * 关键思路：先手可以在第一回合取走 k 个（或不取）；胜负由总和的奇偶与 n*k 的奇偶决定。
 * ###################################################################### */

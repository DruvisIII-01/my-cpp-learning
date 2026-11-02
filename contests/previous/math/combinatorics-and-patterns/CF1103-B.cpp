#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    vector<int> a(n + 1) ;
    string s ; cin >> s ; s = '*' + s ;
    for(int t = 1 ; t <= n ; ++t) a[t] = (s[t] == '1') ;

    for(int t = n ; t >= k + 1 ; t--){
        if(a[t]){
            a[t] = 0 ;
            a[t - k] = 1 - a[t - k] ;
        }
    }
    bool ans = true ;
    for(int t = 1 ; t <= k ; ++t){
        if(a[t]){
            ans = false ;
            break ;
        }
    }if(ans) cout << "YES" ;
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

/* ##################################################################
 * 【题面与关键思路】Tatar TV Show
 * 题目链接：https://codeforces.com/problemset/problem/2236/B
 * 标签：难度 800 | greedy, math, strings
 *
 * 关键思路：从右往左贪心：遇到 1 就把它和左边第 k 个位置一起翻转，最后检查前 k 位是否全为 0。
 * ################################################################## */

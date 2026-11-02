#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;
    int mx = -1 ; 
    for(char ch : s) mx = max(mx, (int)(ch - 'a' + 1)) ;
    cout << mx ;
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
 * 【题面与关键思路】Atilla's Favorite Problem
 * 题目链接：https://codeforces.com/problemset/problem/1760/B
 * 标签：难度 800 | greedy, implementation, strings
 *
 * 关键思路：答案是字符串中最大字符的字母序号。
 * ################################################################## */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;
    s = '*' + s ;
    int ans = -1 ;
    for(int i = 2 ; i <= n ; i++){
        if(s[i] == 'L') {
            ans = i ;
            break ;
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
 * 【题面与关键思路】Passing the Ball
 * 题目链接：https://codeforces.com/problemset/problem/2204/A
 * 标签：难度 800 | brute force, implementation
 *
 * 关键思路：从左往右找第一个传给左侧的球（L 出现在非首位），累计步数。
 * ###################################################################### */

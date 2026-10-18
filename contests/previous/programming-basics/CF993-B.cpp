#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    string s ; cin >> s ;
    string ans ;
    for(int i = s.size() - 1 ; i >= 0 ; i--){
        if(s[i] == 'q') ans += 'p' ;
        else if(s[i] == 'p') ans += 'q' ;
        else ans += 'w' ;
    }
    cout << ans ;
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
 * 【题面与关键思路】Normal Problem
 * 题目链接：https://codeforces.com/problemset/problem/2044/B
 * 标签：难度 800 | implementation,strings
 *
 * 关键思路：旋转 180°：倒序扫描字符串并把 p、q 互换（w 不变），直接输出。
 * ###################################################################### */

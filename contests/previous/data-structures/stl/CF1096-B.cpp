#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;
    stack <int> stk ;
    for(int i = 0 ; i < n ; i++){
        int cur = -1 ;
        if(s[i] == ')') cur = 1 ;
        else cur = 0 ; 
        if(stk.empty()) stk.push(cur) ;
        else {
            int tp = stk.top() ;
            if(tp != cur) stk.pop() ;
            else stk.push(cur) ;
        }
    }if(stk.empty()) cout << "YES" ;
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
 * 【题面与关键思路】Party Monster
 * 题目链接：https://codeforces.com/problemset/problem/2227/B
 * 标签：难度 800 | greedy
 *
 * 关键思路：用栈做括号配对：遇左括号入栈、遇右括号时若栈非空则抵消，最后栈空即 YES。
 * ###################################################################### */

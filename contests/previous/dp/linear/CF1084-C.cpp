#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ;
    stack<char> stk ;
    for(char ch : s){
        if(stk.empty()) stk.push(ch) ;
        else{
            char tp = stk.top() ;
            if(tp == ch) stk.pop() ;
            else stk.push(ch) ;
        }
    }
    if(stk.empty()) cout << "YES" ;
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
 * 【题面与关键思路】Specialty String
 * 题目链接：https://codeforces.com/problemset/problem/2200/C
 * 标签：难度 900 | brute force, greedy, strings
 *
 * 关键思路：用栈消去相邻相同字符，最后栈空则 YES（本质是字符配对消除）。
 * ################################################################## */

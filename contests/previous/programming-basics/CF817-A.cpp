#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ;
    if(n != 5) {
        cout << "NO" ;
        return ;
    }
    vector<int> ans(5) ;
    for(char ch : s){
        if(ch == 'T') ans[0] = 1 ;
        else if(ch == 'i') ans[1] = 1 ;
        else if(ch == 'm') ans[2] = 1 ;
        else if(ch == 'u') ans[3] = 1 ;
        else if(ch == 'r') ans[4] = 1 ;
    }
    bool ok = true ;
    for(int x : ans) {
        if(!x) {
            ok = false ;
            break ;
        }
    }
    if(ok) cout << "YES" ;
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
 * 【题面与关键思路】Spell Check
 * 题目链接：https://codeforces.com/problemset/problem/1722/A
 * 标签：难度 800 | implementation
 *
 * 关键思路：判断字符串长度是否为 5 且恰好由 T、i、m、u、r 五个字母各一个组成：用 5 位标记数组逐字符打钩，最后检查全为 1。
 * ###################################################################### */

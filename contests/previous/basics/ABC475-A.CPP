#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    string s ; cin >> s ;
    for(int i = 0 ; i < s.size() ; ++i) {
        if(i == s.size() - 1) cout << s[i] ;
        else cout << s[i] << 'o' ;
    } 
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】mnclr
 * 题目链接：https://atcoder.jp/contests/abc475/tasks/abc475_a
 * 标签：难度 ABC A | 语法
 *
 * 关键思路：逐字符输出，除最后一个字符外每个字符后面插一个 o。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    string s ; cin >> s ;
    for(char ch : s){
        if(ch == 'A') cout << 'A' ;
        else cout << '.' ;
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】A（字符替换）
 * 题目链接：https://atcoder.jp/contests/abc472/tasks/abc472_a
 * 标签：难度 ABC A | 语法
 *
 * 关键思路：遍历字符串，把 A 原样输出、其它字符替换为点号。
 * ###################################################################### */

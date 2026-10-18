#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    string s ; cin >> s ; 
    string s0 = "" ;
    for(char c : s){
        char ch = c ;
        if(c >= 'a' && c <= 'z') ch -= 32 ;
        s0 += ch ;
    }
    if(s0 == "YES") cout << "YES" ;
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
 * 【题面与关键思路】YES or YES?
 * 题目链接：https://codeforces.com/problemset/problem/1703/A
 * 标签：难度 800 | brute force,implementation,strings
 *
 * 关键思路：把读入串转成大写后与 "YES" 比较。
 * ###################################################################### */

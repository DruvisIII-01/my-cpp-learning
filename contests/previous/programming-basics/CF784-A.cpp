#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int r ; cin >> r ;
    if(r >= 1900) cout << "Division " << 1 ;
    else if(r >= 1600) cout << "Division " << 2 ;
    else if(r >= 1400) cout << "Division " << 3 ;
    else cout << "Division " << 4 ;
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
 * 【题面与关键思路】Division?
 * 题目链接：https://codeforces.com/problemset/problem/1669/A
 * 标签：难度 800 | implementation
 *
 * 关键思路：按分数区间 1900/1600/1400 输出对应的 Division 编号。
 *
 * 题号备注：本题属于 **Codeforces Round 784 (Div. 4)，contestId 1669**（2022-04-21）。
 *    早期文件名写成 CF786 是笔误（官方 Round 786 是 Div.3，题目完全不同），现已改名为 CF784。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    string x ; cin >> x ;
    int sz = x.size() ;
    int y = 1 ;
    for(int t = 1 ; t <= sz ; ++t) y *= 10 ;
    cout << y + 1 ;
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
 * 【题面与关键思路】Good times Good times
 * 题目链接：https://codeforces.com/problemset/problem/2241/B
 * 标签：难度 1100 | constructive algorithms,dfs and similar,math
 *
 * 关键思路：要找"只含 0/1、能被 n 整除、且 > n"的数。10^d + 1（d 为 n 的位数）只含 0/1，且 n=10^d+1 时显然能整除（n 只含 0/1 时亦可用该构造的整除性质），直接输出 10^d(n) + 1。注意用 long long 乘 10。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, c, d ; cin >> a >> b >> c >> d ;
    int e1 = c - b, e2 = a + b, e3 = d - c ;
    if(e1 == e2 && e1 == e3) cout << 3 ;
    else if(e1 == e2 || e1 == e3 || e2 == e3) cout << 2 ;
    else cout << 1 ;
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
 * 【题面与关键思路】Fibonacciness
 * 题目链接：https://codeforces.com/problemset/problem/2060/A
 * 标签：难度 800 | brute force
 *
 * 关键思路：给 a1,a2,a4,a5，a3 可任取。三个候选值 e1=c−b、e2=a+b、e3=d−c 中，a3 取某个候选就能让对应的一个等式成立；统计这三个候选值与 a2−a1、a5−a4 的相等关系，输出能达到的最大 Fibonacciness（1/2/3）。
 * ################################################################## */

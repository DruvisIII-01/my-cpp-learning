#include <bits/stdc++.h>
using namespace std ;

//#define int long long

const double pi = acos(- 1) ;

signed main() {
    int d ; cin >> d ;
    double s = 1.0 * d * d / 4 * pi ;
    printf("%.15lf", s) ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】π
 * 题目链接：https://atcoder.jp/contests/abc449/tasks/abc449_a
 * 标签：难度 ABC A | 几何/语法
 *
 * 关键思路：圆面积 = π d² / 4，直接用 acos(-1) 取 π 并按精度输出。
 * ###################################################################### */

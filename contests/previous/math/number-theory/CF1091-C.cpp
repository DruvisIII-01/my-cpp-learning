#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, m, a, b;
        cin >> n >> m >> a >> b;

        long long g1 = gcd(n, a);
        long long g2 = gcd(m, b);
        long long g = gcd(n, m);

        if (g1 == 1 && g2 == 1 && g <= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Grid Covering
 * 题目链接：https://codeforces.com/problemset/problem/2217/C
 * 标签：难度 1300 | chinese remainder theorem,math,number theory
 *
 * 关键思路：判断用给定的两类方块能否铺满：条件是 gcd(n,a)==1、gcd(m,b)==1 且 gcd(n,m) <= 2；用 gcd 分类讨论。
 * ###################################################################### */

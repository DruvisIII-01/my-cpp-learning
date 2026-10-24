#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve() {
    string s; cin >> s;
    int totalA = count(s.begin(), s.end(), 'A');
    if (s.front() == 'B' || s.back() == 'B') {
        cout << totalA << '\n';
        return;
    }
    int minSeg = INT_MAX, cur = 0;
    for (char c : s) {
        if (c == 'A') cur++;
        else {
            minSeg = min(minSeg, cur);
            cur = 0;
        }
    }
    minSeg = min(minSeg, cur); // 最后一段
    cout << totalA - minSeg ;
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
 * 【题面与关键思路】ABBC or BACB
 * 题目链接：https://codeforces.com/problemset/problem/1873/G
 * 标签：难度 1500 | constructive algorithms,greedy
 *
 * 关键思路：每次操作把 AB 变 BC、BA 变 CB。若串首或串尾是 B，所有 A 都能被覆盖；否则至少要牺牲一个不含 B 的极小 A 段：答案 = count(A) - 最小 A 段长度。
 * ###################################################################### */

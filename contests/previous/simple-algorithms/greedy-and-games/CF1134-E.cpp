#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n + 1), f(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int win = 0;
        int window = 0; // 前 k 个 f 的异或和

        for (int i = 1; i <= n; i++) {
            int fi = 1 ^ window; // F_i mod 2
            f[i] = fi;

            if (a[i] & 1) {
                win ^= fi;
            }

            // 加入 f[i]
            window ^= fi;

            // 窗口左端右移
            if (i - k >= 1) {
                window ^= f[i - k];
            }
        }

        cout << (win ? "Alice" : "Bob") << '\n';
    }

    return 0;
}

/* ##################################################################
 * 【题面与关键思路】Avalanche
 * 题目链接：https://codeforces.com/problemset/problem/2290/E
 * 标签：难度 2290E（新场次，暂无 rating） | dp, games, math
 *
 * 关键思路：按末位奇偶与滑动窗口异或维护"胜负态"：`f[i] = 1 ^ window`（window 是前 k 个 f 的异或），只对 a[i] 为奇数的位置把 f[i] 滚入窗口，最后判断 Alice 是否必胜。
 * ################################################################## */

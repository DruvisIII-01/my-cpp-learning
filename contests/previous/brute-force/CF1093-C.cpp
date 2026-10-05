#include <bits/stdc++.h>

#define int long long

void solve() {
    int p, q;
    std::cin >> p >> q;

    int t = p + 2 * q;
    int k = 2 * t + 1;

    for (int i = std::sqrt(k); i >= 3; --i) {
        if (k % i == 0) {
            int tt = k / i;
            int n = (i - 1) / 2;
            int m = (tt - 1) / 2;

            if (std::abs(n - m) <= p) {
                std::cout << n << " " << m << "\n";
                return;
            }
        }
    }

    std::cout << -1 << "\n";
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int _ = 1;
    std::cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Grid L
 * 题目链接：https://codeforces.com/problemset/problem/2220/C
 * 标签：难度 1400 | brute force, math
 *
 * 关键思路：统计网格中 L 形（两条互相垂直的臂）的个数：枚举拐点与两臂长度，用前缀/后缀连续同色格数把枚举压到 O(nm)。
 * ###################################################################### */

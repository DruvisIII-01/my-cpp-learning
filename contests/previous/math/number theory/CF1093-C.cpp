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
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
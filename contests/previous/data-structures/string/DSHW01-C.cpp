#include <bits/stdc++.h>
using namespace std;

void solve(const string& S, const string& K) {
    bool isKey[128] = {false};
    int k = 0;
    for (unsigned char c : K) {
        if (!isKey[c]) {
            isKey[c] = true;
            ++k;
        }
    }

    if (k == 0) {
        cout << "0\n\n";
        return;
    }

    int cnt[128] = {0};
    int covered = 0;
    int l = 0;
    int n = (int)S.size();

    int bestLen = INT_MAX;
    long long bestCount = 0;
    int bestStart = -1;

    for (int r = 0; r < n; ++r) {
        unsigned char c = S[r];
        if (isKey[c]) {
            if (cnt[c] == 0) ++covered;
            ++cnt[c];
        }

        if (covered == k) {
            // 尽量右移左端点，得到以 r 结尾的最短可行窗口
            while (true) {
                unsigned char lc = S[l];
                if (isKey[lc] && cnt[lc] == 1) break;
                if (isKey[lc]) --cnt[lc];
                ++l;
            }

            int len = r - l + 1;
            if (len < bestLen) {
                bestLen = len;
                bestCount = 1;
                bestStart = l;
            } else if (len == bestLen) {
                ++bestCount;
            }
        }
    }

    if (bestLen == INT_MAX) {
        cout << "0\n\n";
    } else {
        cout << bestCount << "\n\n";
        for (int i = 0; i < bestLen; i += 72) {
            int take = min(72, bestLen - i);
            cout << S.substr(bestStart + i, take) << "\n";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (true) {
        string S;
        while (true) {
            if (!getline(cin, line)) return 0;
            if (!line.empty() && line.back() == '\r') line.pop_back();
            if (line.empty()) break;
            S += line;
        }

        // 连续空行或输入结束
        if (S.empty()) break;

        string K;
        if (!getline(cin, K)) return 0;
        if (!K.empty() && K.back() == '\r') K.pop_back();

        // 消费 K 后面的空行
        getline(cin, line);

        solve(S, K);
    }

    return 0;
}
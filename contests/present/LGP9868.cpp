#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        string w;
        cin >> w;
        s[i] = w;
        sort(s[i].begin(), s[i].end());                       // 升序
        b[i] = w;
        sort(b[i].begin(), b[i].end(), greater<char>());      // 降序
    }

    string ans(n, '1');   // 一次性开好空间，不用不断拼接
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (s[i] >= b[j]) {   // std::string 的比较：首字符不同就立即返回
                ans[i - 1] = '0';
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
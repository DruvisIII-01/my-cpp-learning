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

/* ######################################################################
 * 【题面与关键思路】P9868 [NOIP2023] 三值逻辑（字符串排序比较）
 * 题目链接：https://www.luogu.com.cn/problem/P9868
 * 标签：难度 洛谷 提高+/省选- | 排序, 字符串比较
 *
 * 关键思路：对每个串同时求出"升序最小形式" s[i] 与"降序最大形式" b[i]。答案第 i 位为 0 当且仅当存在 j ≠ i 使 s[i] ≥ b[j] —— 即 i 无论怎么排都不可能严格小于 j。用字符串字典序比较（首字符不同即返回）判断，O(n²)。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> ans(n);
    vector<int> zero, one;  // 存放以0/1结尾的子序列编号
    int cnt = 0;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (!one.empty()) {
                int id = one.back(); one.pop_back();
                ans[i] = id;
                zero.push_back(id);
            } else {
                ++cnt;
                ans[i] = cnt;
                zero.push_back(cnt);
            }
        } else { // '1'
            if (!zero.empty()) {
                int id = zero.back(); zero.pop_back();
                ans[i] = id;
                one.push_back(id);
            } else {
                ++cnt;
                ans[i] = cnt;
                one.push_back(cnt);
            }
        }
    }
    
    cout << cnt << '\n';
    for (int x : ans) cout << x << ' ';
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
 * 【题面与关键思路】Binary String To Subsequences
 * 题目链接：https://codeforces.com/problemset/problem/1399/D
 * 标签：难度 1500 | constructive algorithms, data structures, greedy, implementation
 *
 * 关键思路：把 0/1 分别划成尽量少的"交替子序列"：每个字符优先接到以相反字符结尾的现有子序列，否则新开一条；用两个栈/队列维护编号。
 * ###################################################################### */

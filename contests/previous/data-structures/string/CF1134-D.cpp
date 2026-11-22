#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    string str;
    cin >> str;

    int ans = 0;

    while(true){
        bool ok = true;
        char mx = 'a';

        for(int i = 0; i < n; ++i){
            if(str[i] != str[n - 1 - i]){
                ok = false;
                mx = max(mx, str[i]);
            }
        }

        if(ok) break;

        string nxt;
        nxt.reserve(n);

        for(char ch : str){
            if(ch == mx) nxt.push_back((char)(ch - 1));
            else nxt.push_back(ch);
        }

        str.swap(nxt);
        ++ans;
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}

/* ##################################################################
 * 【题面与关键思路】Letters Down
 * 题目链接：https://codeforces.com/problemset/problem/2290/D
 * 标签：难度 2290D（新场次，暂无 rating） | data structures, dsu, greedy, implementation, strings
 *
 * 关键思路：反复找"回文位置对不上的最大字符 mx"，把所有 mx 统一降一级，直到整串回文；答案即总的降低次数（每轮把 mx 减 1）。
 * ################################################################## */

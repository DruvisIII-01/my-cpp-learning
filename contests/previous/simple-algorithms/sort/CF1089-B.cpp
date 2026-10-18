#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n; cin >> n;
    vector <int> a(n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans += (a[i] <= i);
    }cout << ans;
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
 * 【题面与关键思路】Simply Sitting on Chairs
 * 题目链接：https://codeforces.com/problemset/problem/2210/B
 * 标签：难度 900 | data structures,greedy
 *
 * 关键思路：位置 i 的椅子若 p[i] <= i 则"就座不增加代价"，先把所有这类椅子坐满，剩下的椅子代价至少为 1，交换论证即最优。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
    vector<int> dp(n + 1) ;
    vector<int> tree(n + 1) ;
    vector<vector<pair<int, int>>> lst(n + 1) ;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j < lst[i].size() ; ++j){
            int idx = lst[i][j].first ;
            int val = lst[i][j].second ;
            for(int x = idx ; x <= n ; x += (x & (-x))){
                tree[x] = max(tree[x], val) ;
            }
        }
        int res = 0 ;
        for(int x = i - a[i] - 1 ; x > 0 ; x -= (x & (-x))){
            res = max(tree[x], res) ;
        }dp[i] = res + a[i] ;
        int t = i + a[i] + 1 ;
        if(t <= n) lst[t].push_back(make_pair(i, dp[i])) ;
    }
    int ans = -1 ;
    for(int i = 1 ; i <= n ; i++) ans = max(dp[i], ans) ;
    cout << ans ;
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
 * 【题面与关键思路】Yura and Deadlines
 * 题目链接：https://codeforces.com/problemset/problem/2244/G
 * 标签：难度 1900 | data structures, dp
 *
 * 关键思路：DP 求最大权和不相交区间：dp[i] 表示以 i 结尾的最优值，用树状数组维护"下标 <= i-a[i]-1 的 dp 最大值"，把 dp[i] 在 i+a[i]+1 处插入树状数组。因下标带偏移，用"事件链表 + 单点取 max"实现。
 * ###################################################################### */

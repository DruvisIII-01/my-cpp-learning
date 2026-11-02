#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> f(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> f[t] ;
    
    int sum = (f[1] + f[n]) / (n - 1) ;
    vector<int> pre(n + 1) ;
    for(int t = 1 ; t < n ; ++t){
        int d = f[t + 1] - f[t] ;
        pre[t] = (sum + d) / 2 ;
    }

    pre[n] = sum ; 
    for(int t = 1 ; t <= n ; ++t) cout << pre[t] - pre[t - 1] << ' ' ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】Absolute Cinema
 * 题目链接：https://codeforces.com/problemset/problem/2195/D
 * 标签：难度 1300 | math
 *
 * 关键思路：由 f[1]、f[n] 反推出总和 sum，再用相邻差 d 逐个还原前缀和 `pre[t] = (sum + d)/2`，最后作差得到原数组。
 * ################################################################## */

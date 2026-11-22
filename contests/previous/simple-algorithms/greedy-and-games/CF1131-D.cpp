#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    sort(a.begin() + 1, a.end()) ;

    int ans1 = 0, ans2 = a[n] - a[1] ;
    for(int t = 2 ; t <= n ; ++t)
    ans1 += min((t - 1), (n - t + 1)) * (a[t] - a[t - 1]) ;       
    cout << ans1 << ' ' << ans2 ;
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
 * 【题面与关键思路】Lock and Unlock
 * 题目链接：https://codeforces.com/problemset/problem/2278/D
 * 标签：难度 2278D（新场次，暂无 rating） | greedy
 *
 * 关键思路：排序后相邻差 a[i]−a[i−1] 会被跨越它的区间计数 min(i−1, n−i+1) 次；答案 1 = Σ min(...)·(a[i]−a[i−1])，答案 2 = a[n]−a[1]。
 * ################################################################## */

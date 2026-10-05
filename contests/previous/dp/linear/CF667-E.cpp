#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ; 
    vector <int> x ;
    vector <int> dp(n + 123) ;
    vector <int> suf(n + 123) ;
    for(int t = 1 ; t <= n ; t++) {
        int x0 = -1 ; cin >> x0 ;
        x.push_back(x0) ;
    }
    for(int t = 1 ; t <= n ; t++) {
        int y0 = -1 ; cin >> y0 ;
    }
    
    sort(x.begin(), x.end()) ;
    
    int R = 0 ; 
    for(int L = 0 ; L < n ; L++){
        while(R < n && x[R] <= k + x[L]) R++ ;
        dp[L] = R - L ;
    }

    suf[n - 1] = dp[n - 1] ;
    for(int i = n - 2 ; i >= 0 ; i--) suf[i] = max(suf[i + 1], dp[i]) ;

    int mx = -1 ;
    for(int i = 0 ; i < n ; i++) mx = max(mx, dp[i] + suf[i + dp[i]]) ;
    
    cout << mx ;
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
 * 【题面与关键思路】Two Platforms 两块平台
 * 题目链接：https://codeforces.com/problemset/problem/1409/E
 * 标签：难度 1800 | binary search, dp, sortings, two pointers
 *
 * 关键思路：先把点按 x 排序（y 无关，题目只约束横坐标）：对每个左端点二分出最长可覆盖区间，再用后缀 max 求"两段不重叠区间最大覆盖点数"。关键是把问题降维并预处理后缀最优。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, q ; cin >> n >> q ;
    vector<vector<int>> a(n + 1, vector<int>(n + 1)) ;
    vector<vector<int>> sum(n + 1, vector<int>(n + 1)) ;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j)
        cin >> a[i][j] ;
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j)
        sum[i][j] = a[i][j] + sum[i - 1][j]
        + sum[i][j - 1] - sum[i - 1][j - 1] ;
    }//P(sum) ;

    vector<vector<int>> pre1(n + 1, vector<int>(n + 1)) ;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j)
        pre1[i][j] = pre1[i][j - 1] + a[i][j] ;
        //第i行前j个数之和
    }//P(pre1) ;
    vector<vector<int>> prei(n + 1, vector<int>(n + 1)) ;
    for(int j = 1 ; j <= n ; ++j){
        for(int i = 1 ; i <= n ; ++i)
        prei[i][j] = prei[i - 1][j] + i * pre1[i][j] ;
        //固定j，对pre1求遍历i的前缀和
    }//P(prei) ;
    vector<vector<int>> prei0(n + 1, vector<int>(n + 1)) ;
    for(int j = 1 ; j <= n ; ++j){
        for(int i = 1 ; i <= n ; ++i)
        prei0[i][j] = prei0[i - 1][j] + pre1[i][j] ;
    }//P(prei0) ;
    vector<vector<int>> pre2(n + 1, vector<int>(n + 1)) ;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j)
        pre2[i][j] = pre2[i][j - 1] + j * a[i][j] ;
    }//P(pre2) ;
    vector<vector<int>> prej(n + 1, vector<int>(n + 1)) ;
    for(int j = 1 ; j <= n ; ++j){
        for(int i = 1 ; i <= n ; ++i)
        prej[i][j] = prej[i - 1][j] + pre2[i][j] ;
    }//P(prej) ;

    //cout << "=========================" << endl ;
    for(int t = 1 ; t <= q ; ++t){
        int x1, x2, y1, y2 ; cin >> x1 >> y1 >> x2 >> y2 ;
        int M = x2 - x1 + 1, N = y2 - y1 + 1 ;
        //M 表示行数，N 表示列数
        int ans = sum[x2][y2] - sum[x2][y1 - 1]
        - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] ;
        
        int ansi1 = prei[x2][y2] - prei[x1 - 1][y2]
        - x1 * (prei0[x2][y2] - prei0[x1 - 1][y2]) ;
        int ansi2 = prei[x2][y1 - 1] - prei[x1 - 1][y1 - 1]
        - x1 * (prei0[x2][y1 - 1] - prei0[x1 - 1][y1 - 1]) ;

        int ansj1 = prej[x2][y2] - prej[x1 - 1][y2]
        -(prej[x2][y1 - 1] - prej[x1 - 1][y1 - 1]) ;
        int ansj2 = y1 * ((prei0[x2][y2] - prei0[x1 - 1][y2])
        - (prei0[x2][y1 - 1] - prei0[x1 - 1][y1 - 1])) ;

        int ansi = ansi1 - ansi2 ;
        int ansj = ansj1 - ansj2 ;
        ans += (ansi * N + ansj) ;
        cout << ans << ' ' ;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << '\n' ;
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Hard Demon Problem
 * 题目链接：https://codeforces.com/problemset/problem/2044/H
 * 标签：难度 2100 | constructive algorithms,data structures,dp,implementation,math
 *
 * 关键思路：要求 Σ a[i][j]·(i·N + j) 形式的二维加权矩形和（i、j 相对矩形左上角）。预处理四组前缀和：普通二维前缀和 S、按行的前缀和 pre1、加权 i·pre1 的列前缀和 prei、加权 j·a 的行前缀和 pre2 及其列前缀和 prej；查询时用容斥把区间和换算到"相对坐标"再线性组合，O(1) 回答。是"加权前缀和 + 容斥"的高难度综合题。
 *
 * 本题已归档到 math/prefix-sum：题目本质是二维前缀和 + 加权前缀和的容斥计算。
 * ###################################################################### */

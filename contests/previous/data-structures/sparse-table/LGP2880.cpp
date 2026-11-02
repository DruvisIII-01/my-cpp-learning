#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int LIMIT = 20 ;

signed main() {
    int n, q ; cin >> n >> q ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    // for(int t = 1 ; t <= n ; ++t) cout << a[t] << ' ' ;
    // cout << endl ; cout << endl ;

    vector<vector<int>> st_mi(n + 1, vector<int>(LIMIT)) ;
    for(int t = 1 ; t <= n ; ++t) st_mi[t][0] = a[t] ;
    for(int d = 1 ; d < LIMIT ; ++d){
        for(int t = 1 ; t <= n ; ++t){
            int mv = 1 << (d - 1), next = min(n, mv + t) ;
            st_mi[t][d] = min(st_mi[t][d - 1], st_mi[next][d - 1]) ;
        }
    }
    
    vector<vector<int>> st_mx(n + 1, vector<int>(LIMIT)) ;
    for(int t = 1 ; t <= n ; ++t) st_mx[t][0] = a[t] ;
    for(int d = 1 ; d < LIMIT ; ++d){
        for(int t = 1 ; t <= n ; ++t){
            int mv = 1 << (d - 1), next = min(n, mv + t) ;
            st_mx[t][d] = max(st_mx[t][d - 1], st_mx[next][d - 1]) ;
        }
    }
    // for(int d = 0 ; d < LIMIT / 2 ; ++d){
    //     for(int t = 1 ; t <= n ; ++t) cout << st_mx[t][d] << ' ' ; cout << endl ;
    // }

    for(int TTT = 1 ; TTT <= q ; ++TTT){
        int left, right ; cin >> left >> right ;
        if(right == left) cout << 0 << endl ;
        else {
            int op = 0 ;
            while(left + (1 << op) - 1 <= right) op++ ; op-- ;
            //cout << op << endl ; 
            int mx = max(st_mx[left][op], st_mx[right - (1 << op) + 1][op]) ; //cout << mx << endl ;
            int mi = min(st_mi[left][op], st_mi[right - (1 << op) + 1][op]) ; //cout << mi << endl ; 
            cout << mx - mi << endl ; 
        }
    } 
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】P2880 [USACO07JAN] Balanced Lineup G
 * 题目链接：https://www.luogu.com.cn/problem/P2880
 * 标签：难度 洛谷 普及/提高- | ST 表, 区间最值
 *
 * 关键思路：ST 表同时维护区间最大值与最小值，查询时取两段重叠区间，答案 = max − min。
 * ################################################################## */

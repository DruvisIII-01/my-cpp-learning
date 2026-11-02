#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int LIMIT = 15 ;

signed main() {
    int n, q ; cin >> n >> q ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    vector<vector<int>> st_gcd(n + 1, vector<int>(LIMIT)) ;
    for(int t = 1 ; t <= n ; ++t) st_gcd[t][0] = a[t] ;
    for(int d = 1 ; d < LIMIT ; ++d){
        for(int t = 1 ; t <= n ; ++t){
            int mv = 1 << (d - 1), next = min(n, t + mv) ;
            st_gcd[t][d] = __gcd(st_gcd[t][d - 1], st_gcd[next][d - 1]) ;
        }
    }

    for(int QWQ = 1 ; QWQ <= q ; ++QWQ){
        int left, right ; cin >> left >> right ;
        if(left == right) cout << a[right] << endl ;
        else{
            int op = 0 ;
            while(left + (1 << op) - 1 <= right) op++ ; op-- ;
            cout << __gcd(st_gcd[left][op], st_gcd[right - (1 << op) + 1][op]) << endl ;
        }
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】P1890 gcd 区间
 * 题目链接：https://www.luogu.com.cn/problem/P1890
 * 标签：难度 洛谷 | ST 表, gcd
 *
 * 关键思路：ST 表维护区间 gcd：`st[i][k]` 表示从 i 起长度 2^k 的 gcd，查询取两段重叠区间的 gcd。
 * ################################################################## */

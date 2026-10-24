#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    vector<int> b(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
    for(int i = 1 ; i <= n ; ++i) cin >> b[i] ;

    //special judge
    bool impossible = true ;
    for(int i = 1 ; i <= n ; ++i){
        if(a[i] > b[i]){
            impossible = false ;
            break ;
        }
    }

    if(impossible){
        cout << "No" ;
        return 0 ;
    }

    __int128_t tot = 0 ;
    vector<int> ans(n + 1) ;
    for(int i = 1 ; i <= n ; ++i){
        if(a[i] > b[i]) ans[i] = (int)1e18 ;
        else ans[i] = 1 ;
        tot += (__int128_t)ans[i] * (a[i] - b[i]) ;
    }
    if(tot > 0){
        cout << "Yes" << endl ;
        for(int i = 1 ; i <= n ; ++i) cout << ans[i] << ' ' ;
    }else cout << "No" ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Outweigh
 * 题目链接：https://atcoder.jp/contests/abc474/tasks/abc474_d
 * 标签：难度 ABC D | 构造/贪心
 *
 * 关键思路：要让 Σans[i]*(a[i]-b[i]) > 0：对 a[i]>b[i] 的位置取极大值 1e18、其余取 1，再用 __int128 校验是否为正；输出任一方案。
 * ###################################################################### */

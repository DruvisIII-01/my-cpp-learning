#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n ; cin >> n ;
    vector<int> l(n + 1) ;
    int sum = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        cin >> l[i] ;
        sum += l[i] ;
    }

    int mi = 2000000 ;
    int cur = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        cur += l[i] ;
        mi = min(mi, abs(2 * cur - sum)) ;
    }cout << mi ; 
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Break a Stick
 * 题目链接：https://atcoder.jp/contests/abc472/tasks/abc472_b
 * 标签：难度 ABC B
 *
 * 关键思路：前缀和求 |2*pre[i] - sum| 的最小值，即分成两段长度差最小。
 * ###################################################################### */

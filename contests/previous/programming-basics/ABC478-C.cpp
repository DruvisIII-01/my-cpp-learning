#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n, k ; cin >> n >> k ;
    vector<int> a(n + 1) ;
    vector<int> b(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) {
        cin >> a[i] ;
        b[i] = a[i] ;
    }

    sort(a.begin() + 1, a.end()) ;
    
    int fi = -1 ;
    for(int i = 1 ; i <= n ; ++i) {
        if(a[i] != b[i]){
            fi = i ;
            break ;
        }
    }
    int ls = -1 ;
    for(int i = n ; i >= 1 ; i--) {
        if(a[i] != b[i]){
            ls = i ;
            break ;
        }
    }
    if(ls - fi + 1 <= k) cout << "Yes" ;
    else cout << "No" ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Sort Subarray
 * 题目链接：https://atcoder.jp/contests/abc478/tasks/abc478_c
 * 标签：难度 ABC C | 排序 + 区间比较
 *
 * 关键思路：把原数组排序后与原数组逐位比较，找到第一个不同的位置 L 与最后一个不同的位置 R；只有把 [L, R] 这一段整体排序才可能让数组有序，故 R − L + 1 ≤ k 时输出 Yes。
 * 边界：数组本来有序时 L 与 R 保持初值 −1，此时 R − L + 1 = 1 ≤ k（k ≥ 1），输出 Yes，正好正确。
 * ###################################################################### */

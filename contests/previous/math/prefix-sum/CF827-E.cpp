#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, q ; cin >> n >> q ;
    vector<int> a(n + 1) ;
    vector<int> pre(n + 1) ;
    for(int t = 1 ; t <= n ; ++t){
        cin >> a[t] ; int tmp = a[t] ; 
        a[t] = max(a[t], a[t - 1]) ;
        pre[t] = pre[t - 1] + tmp ;
    }
    for(int t = 1 ; t <= q ; ++t){
        int k ; cin >> k ; 
        int left = 0, right = n + 1 ;
        while(left + 1 != right){
            int mid = (left + right) >> 1 ;
            if(a[mid] > k) right = mid ;
            else left = mid ;
        }
        cout << pre[left] << ' ' ;
    }
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
 * 【题面与关键思路】Scuza
 * 题目链接：https://codeforces.com/problemset/problem/1742/E
 * 标签：难度 1200 | binary search,greedy,math
 *
 * 关键思路：预处理前缀最大值 a[i] = max(a[i], a[i-1])（记录"能爬过前 i 级台阶所需的腿长"）与前缀和 pre[i]；每次询问 k 二分出最大的 i 使 a[i] ≤ k，答案就是 pre[i]。前缀和最典型的"预处理 + 二分查询"。
 *
 * 本题已归档到 math/prefix-sum：前缀最大值 + 前缀和 + 二分查询。
 * ###################################################################### */

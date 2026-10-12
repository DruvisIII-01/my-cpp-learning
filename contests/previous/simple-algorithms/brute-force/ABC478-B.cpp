#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n, V ; cin >> n >> V ;
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    int M = -114514 ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = i + 1 ; j <= n ; ++j){
            for(int k = j + 1 ; k <= n ; ++k){
                if(i + j + k <= V) M = max(M, a[i] + a[j] + a[k]) ;
            }
        }
    }

    cout << M ; 
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Topping
 * 题目链接：https://atcoder.jp/contests/abc478/tasks/abc478_b
 * 标签：难度 ABC B | 三重枚举
 *
 * 关键思路：n 较小，直接三重循环枚举 i<j<k，在总下标和 i+j+k ≤ V 的约束下取 a[i]+a[j]+a[k] 的最大值。
 * ###################################################################### */

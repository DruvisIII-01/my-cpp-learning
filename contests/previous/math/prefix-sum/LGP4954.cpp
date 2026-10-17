#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    vector <int> pre(n + 1) ;
    vector <int> w(n + 1) ;
    vector <int> dp(n + 1) ;
    deque <int> dq ;
    for(int i = n ; i >= 1 ; i--) cin >> a[i] ;
    for(int i = 1 ; i <= n ; i++) pre[i] = pre[i - 1] + a[i] ;

    //brute force linear dp
    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = 0 ; j < i ; j++){
    //         //find the first j, w[j] + pre[j] <= pre[i] 
    //         if(pre[i] - pre[j] >= w[j]){
    //             dp[i] = dp[j] + 1 ;
    //             w[i] = pre[i] - pre[j] ;
    //             break ;
    //         }
    //     }
    // }

    int pos = 0 ;
    for(int i = 1 ; i <= n ; i++){
        //find the first j, w[j] + pre[j] <= pre[i]
        //dq increases with pre + w(last width) 
        //and decreases with index(reverse)
        while(!dq.empty() && pre[dq.front()] + w[dq.front()] <= pre[i]){
            pos = dq.front() ;
            dq.pop_front() ;
        }
        dp[i] = dp[pos] + 1 ;
        w[i] = pre[i] - pre[pos] ;
        while(!dq.empty() && pre[dq.back()] + w[dq.back()] > pre[i] + w[i]) 
        dq.pop_back() ;
        dq.push_back(i) ;
    }
    cout << dp[n] ;
    //a[i] reverse 
    //dp[i], 1 to i, max floors
    //w[i], min width of the floor end with a[i]
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】P4954 [USACO09OPEN] Tower of Hay G
 * 题目链接：https://www.luogu.com.cn/problem/P4954
 * 标签：难度 洛谷 省选/NOI- | dp, 单调队列优化
 *
 * 关键思路：从后往前分层，记 f[i] 为前 i 包的最大层数、w[i] 为最后一层最小宽度；有单调性 f 与 w 同增，用单调队列（deque）维护候选转移点，O(n)。
 *
 * 本题已归档到 math/prefix-sum：前缀和 + 单调队列优化。
 * ###################################################################### */

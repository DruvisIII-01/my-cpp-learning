#include <bits/stdc++.h>
using namespace std ;

#define int long long

int k, n ;
int dist(int i, int j){
    if(i < j) swap(i, j) ;
    return min(i - j, n - i + j) ;
}
bool check(int D, vector<int>& g){
    vector<int> h1(n + 2), h2(n + 2), G(n + 1) ;
    h1[1] = h1[n + 1] = g[n + 1] ;
    for(int t = 2 ; t <= n ; ++t) h1[t] = max(g[t], h1[t - 1] - D) ;
    h2[1] = h2[n + 1] = g[n + 1] ;
    for(int t = n ; t >= 1 ; t--) h2[t] = max(g[t], h2[t + 1] - D) ;
    for(int t = 1 ; t <= n ; ++t) G[t] = max(h1[t], h2[t]) ;

    int res = 0 ;
    for(int t = 1 ; t <= n ; ++t) {
        res += G[t] - g[t] ;
        if(res > k) return false ;  
    }
    return res <= k ;
}

void solve(){
    cin >> n >> k ; 
    vector<int> a(n + 1) ; for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    //find the mx of array and its idx
    int mx = -1, mx_id = -1 ;
    for(int t = 1 ; t <= n ; ++t) {
        if(a[t] > mx){
            mx = a[t] ;
            mx_id = t ;
        }
    }
    //rotate the array to make the mx to be first
    vector<int> g(n + 3) ;
    for(int t = mx_id ; t <= n ; ++t) g[t - mx_id + 1] = a[t] ;
    for(int t = 1 ; t < mx_id ; ++t) g[t + n - mx_id + 1] = a[t] ;
    g[n + 1] = a[mx_id] ; 

    //find the left and right bond of binary-search
    int left = -1, right = mx ;
    while(left + 1 != right){
        int mid = (left + right) >> 1 ;
        if(check(mid, g)) right = mid ; 
        else left = mid ;
    }cout << right ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】Lakeside Trail (Hard Version)
 * 题目链接：https://codeforces.com/problemset/problem/2290/G2
 * 标签：难度 2290G2（新场次，暂无 rating） | binary search, dp, greedy, math
 *
 * 关键思路：与 easy 版同一个 check，但数据范围更大：用两遍方向扫描（前缀 P 型 + 后缀 N 型）代替暴力枚举环形断点，配合二分答案做到 O(n log V)。
 * ################################################################## */

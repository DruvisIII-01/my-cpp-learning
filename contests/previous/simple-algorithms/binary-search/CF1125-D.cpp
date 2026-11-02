#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 224524 ;
int a[MAXN], b[MAXN], c[MAXN], n, k ;

bool check(int reach){
    int cost = 0 ;
    for(int t = 1 ; t <= n ; ++t){
        int cur = a[t] + b[t] + c[t] ;
        if(cur < reach){
            if(a[t] == b[t] && b[t] == c[t]) return false ;
            else if(a[t] <= b[t] && b[t] <= c[t]){
                int minus = 1 + min(abs(c[t] - b[t]), abs(b[t] - a[t])) ;
                cost += (minus * 2) + (reach - cur) ;
            }
            else cost += reach - cur ;
        }if (cost > k) return false; 
    }return cost <= k ;
}

void solve(){
    cin >> n >> k ; 
    int mi = __LONG_LONG_MAX__ ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] >> b[t] >> c[t] ;
        mi = min(mi, a[t] + b[t] + c[t]) ;
    }
    int left = mi, right = mi + 1 + k ;
    while(left + 1 != right){
        int mid = (left + right) / 2 ;
        if(check(mid)) left = mid ;
        else right = mid ;
    } cout << left ;
    for(int t = 1 ; t <= n ; ++t) a[t] = b[t] = c[t] = 0 ;
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
 * 【题面与关键思路】Precision Alignment
 * 题目链接：https://codeforces.com/problemset/problem/2275/D
 * 标签：难度 1300 | binary search, brute force, greedy, implementation
 *
 * 关键思路：二分目标值 reach，check 里逐项算把三项之和提到 reach 的最小代价（三项相等时不可行；严格递增时还要额外 +2）。
 * ################################################################## */

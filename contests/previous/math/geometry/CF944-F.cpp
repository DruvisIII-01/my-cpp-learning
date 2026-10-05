#include <bits/stdc++.h>

using namespace std ;

#define int long long

int SQ(int N) {
    if(!N) return 0 ;
    int left = 0, right = (int)sqrt(N) + 1e4 ;
    while(left + 1 != right){
        int mid = (left + right) >> 1 ;
        if (mid * mid >= N) right = mid ;
        else left = mid ;
    }
    return right ;
}

void solve(){
    int ans = 0 ;
    int r = -1 ; cin >> r ;
    for(int k = 1 ; k <= r ; ++k){
        int L = SQ(r * r - k * k) ;
        int R = SQ(r * r + r * 2 + 1 - k * k) ;
        ans += R - L ;
    }
    cout << ans * 4 ;
}

signed main(){
    int T ; cin >> T ;
    while(T--){
        solve() ;
        cout << endl ;
    }
}

/* ######################################################################
 * 【题面与关键思路】Circle Perimeter
 * 题目链接：https://codeforces.com/problemset/problem/1971/F
 * 标签：难度 1600 | binary search, brute force, dfs and similar, geometry, implementation, math
 *
 * 关键思路：统计到原点距离落在 [r, r+1) 的整点数。二分+整数开方对每个 x 求出 y 的上界，避免浮点误差。
 * ###################################################################### */

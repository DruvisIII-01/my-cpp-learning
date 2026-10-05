#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, c, k ; cin >> n >> c >> k ;
    vector <int> a(n + 1) ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
    sort(a.begin() + 1, a.begin() + n + 1) ;
    int cur = c, rem = k ;
    for (int i = 1 ; i <= n ; i++){
        if(a[i] <= cur){
            int d = cur - a[i] ;
            int x = min(rem, d) ;
            rem -= x ;
            cur += x + a[i] ;
        }
        else break ;
    }cout << cur ;
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
 * 【题面与关键思路】Flip Flops
 * 题目链接：https://codeforces.com/problemset/problem/2209/A
 * 标签：难度 800 | greedy
 *
 * 关键思路：排序后按容量 c 一组、每组内相邻差不超过 k 贪心装箱，统计组数。
 * ###################################################################### */

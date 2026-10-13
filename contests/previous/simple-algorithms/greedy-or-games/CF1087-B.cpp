#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    for(int i = 1 ; i <= n ; i++){
        int mx = 0, mi = 0 ;
        for(int j = i + 1 ; j <= n ; j++){
            mx += (a[j] > a[i]) ;
            mi += (a[j] < a[i]) ;
        }
        cout << max(mx, mi) << ' ';
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
 * 【题面与关键思路】Array
 * 题目链接：https://codeforces.com/problemset/problem/2209/B
 * 标签：难度 900 | greedy
 *
 * 关键思路：k 取极大/极小等价于只比较 a[i] 大小关系；对每个 i 统计其后比 a[i] 大/小的个数即可。
 * ###################################################################### */

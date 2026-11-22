#include <bits/stdc++.h>
using namespace std ;

#define int long long
// 1 2 3 4 
// 3 2 1 4 
// 1 4 3 2 
// 3 4 1 2 

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    if(n == 1){
        cout << a[1] ;
        return ;
    }

    //sort(a.begin(), a.end()) ;
    vector<int> b(n + 1) ;
    int minus = -1 ;
    for(int t = 1 ; t <= n ; ++t){
        b[t] = a[t] * minus ; 
        minus = - minus ; 
    }sort(b.begin() + 1, b.end(), greater<int>()) ;

    int ans = 0 ; 
    for(int t = 1 ; t <= n / 2 ; ++t) ans += b[t] ;
    for(int t = n / 2 + 1 ; t <= n ; ++t) ans -= b[t] ;
    cout << ans ; 
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
 * 【题面与关键思路】Swap and Negate
 * 题目链接：https://codeforces.com/problemset/problem/2278/E
 * 标签：难度 2278E（新场次，暂无 rating） | constructive algorithms, greedy
 *
 * 关键思路：把 a 按下标奇偶交替取负得到 b，再把 b 降序排序后按"正负交替"放回原位置，即可保证相邻元素异号且操作数最少。
 * ################################################################## */

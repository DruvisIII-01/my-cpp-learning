#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    bool mp[n + 1][2] = {} ;
    for(int i = 1 ; i <= n ; i++){
        int x, y ; cin >> x >> y ;
        mp[x][y] = true ;
    }int ans = 0 ;
    for(int x = 0 ; x <= n ; x++){
        if(mp[x][0] && mp[x][1]) ans += (n - 2) ;
    }for(int x = 1 ; x < n ; x++){
        if(mp[x][0] && mp[x - 1][1] && mp[x + 1][1]) ans++ ;
        if(mp[x][1] && mp[x - 1][0] && mp[x + 1][0]) ans++ ;
    }cout << ans ;
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
 * 【题面与关键思路】Satyam and Counting
 * 题目链接：https://codeforces.com/problemset/problem/2009/D
 * 标签：难度 1400 | geometry,math
 *
 * 关键思路：把点按 (x, y∈{0,1}) 存表：对每个 x 若上下都存在则与其他两点组成 n-2 个直角三角形；再统计形如 (x,0)-(x+1,1)-(x+2,0) 的等腰直角结构，逐 x 计数。
 * ###################################################################### */

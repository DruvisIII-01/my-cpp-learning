#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    map <pair<int, int>, int> mp1 ;
    map <pair<int, int>, int> mp2 ;
    map <pair<int, int>, int> mp3 ;
    map <string, int> f ;
    int ans = 0 ;
    for(int i = 1 ; i <= n - 2 ; i++){
        int x = a[i], y = a[i + 1], z = a[i + 2] ;
        int cnt1 = mp1[{y, z}], cnt2 = mp2[{x, z}], cnt3 = mp3[{x, y}] ;
        string key = to_string(x) + ',' + to_string(y) + ',' + to_string(z) ; 
        int cur = f[key] ;
        ans += cnt1 - cur + cnt2 - cur + cnt3 - cur ;

        mp1[{y, z}]++ ;
        mp2[{x, z}]++ ;
        mp3[{x, y}]++ ;
        f[key]++ ;
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
 * 【题面与关键思路】How Does the Rook Move?
 * 题目链接：https://codeforces.com/problemset/problem/1957/C
 * 标签：难度 1600 | combinatorics,dp,math
 *
 * 关键思路：统计三元组/二元组的重复贡献：用 map 记录每个二元组出现次数，组合计数后按容斥扣除重复，O(n log n)。
 * ###################################################################### */

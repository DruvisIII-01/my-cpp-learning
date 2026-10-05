#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n+1,0) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    int ans = 1, tmp = a[1] ;
    for(int i = 2 ; i <= n ; i++) {
        if(a[i] >= tmp){
            ans++;
            tmp = a[i] ;
        }
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
 * 【题面与关键思路】Right Maximum
 * 题目链接：https://codeforces.com/problemset/problem/2204/B
 * 标签：难度 800 | greedy
 *
 * 关键思路：从左往右贪心取"当前所见最大值"的更新点，统计单调不减前缀中的记录数。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    vector <int> cnt(3) ;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i] ;
        if(a[i] % 2) cnt[0]++ ;
        else if(a[i] % 4 == 2) cnt[1]++ ;
        else cnt[2]++ ;
    }
    int ans = 0 ; 
    for(int i : cnt) ans = max(ans, i) ;
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

/* ######################################################################
 * 【题面与关键思路】Minus Two
 * 题目链接：https://codeforces.com/problemset/problem/2259/B
 * 标签：难度 800 | math,number theory
 *
 * 关键思路：每次可删两个相同数或两个相差 2 的数；按奇偶分类统计并贪心配对，答案为最大可删对数。
 * ###################################################################### */

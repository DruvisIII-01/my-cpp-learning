#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    int rest = 0 ;
    bool ans = true ;
    for(int i = 1 ; i <= n ; ++i){
        if(a[i] >= i) rest += (a[i] - i) ;
        else {
            if(rest + a[i] < i) {
                ans = false ;
                break ;
            }else rest -= (i - a[i]) ;
        }
    }

    if(ans) cout << "YES" ;
    else cout << "NO" ;
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
 * 【题面与关键思路】Nikita and Books
 * 题目链接：https://codeforces.com/problemset/problem/2244/B
 * 标签：难度 800 | greedy,math,sortings
 *
 * 关键思路：从左往右模拟书架，用 rest 记录之前多出来的书；每次把 rest 平摊到当前书架上，超过则失败。
 * ###################################################################### */

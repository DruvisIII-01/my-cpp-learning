#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    
    bool ans = false ;
    for(int t = 1 ; t <= n ; ++t){
        if(a[t] == 67){
            ans = true ;
            break ;
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

/* ##################################################################
 * 【题面与关键思路】Sieve of Erato67henes
 * 题目链接：https://codeforces.com/problemset/problem/2195/A
 * 标签：难度 800 | math, number theory
 *
 * 关键思路：扫一遍数组看有没有 67 即可（题名致敬埃氏筛，但判断只需线性扫描）。
 * ################################################################## */

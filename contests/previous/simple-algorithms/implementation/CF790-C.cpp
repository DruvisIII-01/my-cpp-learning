#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ;
    vector <string> s(n + 1) ;
    for(int i = 1 ; i <= n ; i++){
        cin >> s[i] ;
    }
    int mi = LLONG_MAX ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = i + 1 ; j <= n ; j++){
            int cur = 0 ;
            for(int k = 0 ; k < m ; k++){
                cur += abs((int)s[i][k] - (int)s[j][k]) ;
            }
            mi = min(mi, cur) ;
        }
    }
    cout << mi ;
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
 * 【题面与关键思路】Most Similar Words
 * 题目链接：https://codeforces.com/problemset/problem/1676/C
 * 标签：难度 800 | brute force,greedy,implementation,math,strings
 *
 * 关键思路：n 很小，双重循环枚举所有字符串对，逐位计算字母距离之和取最小。
 * ###################################################################### */

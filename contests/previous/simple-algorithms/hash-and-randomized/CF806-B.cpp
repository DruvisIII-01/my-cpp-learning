#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ;
    vector<int> hsh(26) ;
    int ans = 0 ;
    for(int i = 0 ; i < n ; ++i){
        char ch = s[i] ;
        if(!hsh[ch - 'A']) ans += 2 ;
        else ans++ ;
        hsh[ch - 'A']++ ;
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
 * 【题面与关键思路】ICPC Balloons
 * 题目链接：https://codeforces.com/problemset/problem/1703/B
 * 标签：难度 800 | data structures,implementation
 *
 * 关键思路：用 26 位计数数组：第一次遇到的题得 2 分，之后每次 1 分。
 * ###################################################################### */

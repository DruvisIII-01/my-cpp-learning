#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    string s ; cin >> s ; s = '*' + s ;
    int t = n / k ; int ans = 0 ;
    for(int i = 0 ; i < t ; i++){
        bool has_zero = false ;
        for(int j = 1 ; j <= k ; j++){
            if(s[i * k + j] == '0'){
                has_zero = true ;
                break ;
            }
        }ans += has_zero ;
    }cout << t - ans ;
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
 * 【题面与关键思路】Moo Language School
 * 题目链接：https://codeforces.com/problemset/problem/2259/A
 * 标签：难度 800 | brute force,greedy,two pointers
 *
 * 关键思路：把字符串按长度 k 分块，统计每块内 1 的个数（或是否含 0），累加答案。
 * ###################################################################### */

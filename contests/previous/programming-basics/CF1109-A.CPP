#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;
    
    int mx = 0 ;
    int cur = 0 ;
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == '*'){
            mx = max(mx, cur) ;
            cur = 0 ;
        }else{
            cur++ ;
            if(i == n - 1) mx = max(mx, cur) ; 
        }
    }cout << (mx + 1) / 2 ;
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
 * 【题面与关键思路】Iskander and Drawings
 * 题目链接：https://codeforces.com/problemset/problem/2244/A
 * 标签：难度 800 | dp,games,greedy,strings
 *
 * 关键思路：统计最长连续"非星号"段长度 L，答案 = (L+1)/2（每次操作可覆盖两个）。
 * ###################################################################### */

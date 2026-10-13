#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ; s = '*' + s ;
    int cnt0 = 0 ; 
    for(int t = 1 ; t <= n ; ++t) cnt0 += (s[t] == '0') ;
    int cnt1 = n - cnt0 ;
    
    //calculate segs and special judge
    int segs = 0 ;
    int fi = 1 ;
    for(int i = 1 ; i <= n ; ++i){
        if(s[i] != s[fi]) {
            segs++ ;
            fi = i ;
        }if(i == n) segs++ ;
    }//cout << segs << endl ;
    if(segs == 2) cout << 2 ;
    else cout << 1 ;
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
 * 【题面与关键思路】RemovevomeR
 * 题目链接：https://codeforces.com/problemset/problem/2241/C
 * 标签：难度 1000 | greedy
 *
 * 关键思路：一次操作可以删掉一个回文子串。统计 01 串的"极大连续段数" segs：segs == 2 时两段无法合并，需要 2 次；否则总能一次删完，答案是 1。
 * ###################################################################### */

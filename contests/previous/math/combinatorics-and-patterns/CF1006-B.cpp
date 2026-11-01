#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ;
    int cnt1 = 0 ;//count the chr '_'
    int cnt2 = 0 ;//count the chr '-'
    for(char ch : s){
        cnt1 += (ch == '_') ;
        cnt2 += (ch == '-') ;
    }
    cout << cnt1 * (cnt2 - cnt2 / 2) * (cnt2 / 2) ;
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
 * 【题面与关键思路】Having Been a Treasurer in the Past, I Help Goblins Deceive
 * 题目链接：https://codeforces.com/problemset/problem/2072/B
 * 标签：难度 900 | combinatorics,constructive algorithms,strings
 *
 * 关键思路：统计 '_' 与 '-' 的个数，按贪心把减号平均分成三段（x*y*z 最大时尽量均分）相乘即答案；注意用 long long。
 * ###################################################################### */

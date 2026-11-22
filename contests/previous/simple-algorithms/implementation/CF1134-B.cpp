#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string str ; cin >> str ; 
    char color = 'R' ;

    int cnt = 0 ; 
    for(char ch : str){
        if(ch != color) {
            color = ch ;
            cnt++ ;
        }//automatically switch
        if(color == 'R') color = 'B' ;
        else color = 'R' ;
    }cout << cnt ; 
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
 * 【题面与关键思路】Stubborn Pen
 * 题目链接：https://codeforces.com/problemset/problem/2290/B
 * 标签：难度 2290B（新场次，暂无 rating） | implementation, strings
 *
 * 关键思路：按"当前期望颜色"逐字符扫描，不匹配就换色并计数（颜色在 R/B 之间自动交替），输出换色次数。
 * ################################################################## */

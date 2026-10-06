#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ; s = '*' + s ;
    
    int dec = 0 ;
    for(int i = 2 ; i < n ; ++i){
        char ch1 = s[i - 1] ;
        char ch2 = s[i] ;
        char ch3 = s[i + 1] ;
        if(ch2 != ch1 && ch2 != ch3){
            if(ch1 == ch3) dec = max(dec, (int)2) ;
            else dec = max((int)1, dec) ;
        }
    }

    int diff = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        if(s[i] != s[i - 1]) diff++ ;
    }

    cout << diff - dec ;
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
 * 【题面与关键思路】Evanescent
 * 题目链接：https://codeforces.com/problemset/problem/2254/B
 * 标签：难度 900 | implementation, strings, two pointers
 *
 * 关键思路：统计相邻不同字符的对数得到 diff，再看能否通过删除一个"孤立的中间字符"额外减少 1 或 2 次变化，答案 = diff - dec。
 * ###################################################################### */

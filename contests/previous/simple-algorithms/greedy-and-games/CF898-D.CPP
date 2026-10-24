#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ; 
    string s ; cin >> s ; s = '*' + s ;
    int index = 1, cnt = 0 ; 
    while(index <= n){
        if(s[index] == 'W') index++ ;
        else{
            cnt++ ;
            index += k ;
        }
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

/* ######################################################################
 * 【题面与关键思路】1D Eraser
 * 题目链接：https://codeforces.com/problemset/problem/1873/D
 * 标签：难度 800 | greedy,implementation,two pointers
 *
 * 关键思路：从左往右扫：遇到黑色格就把它和右边 k-1 格一起刷白，答案即刷的次数（贪心不亏）。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, c ; cin >> a >> b >> c ;
    if(abs(a + c - b) >= abs(a - b)){
        a += c ;
        c = 0 ;
    }
    if(abs(b + c - a) <= abs(b - a)){
        b += c ;
        c = 0 ;
    }
    cout << abs(a - b) ;
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
 * 【题面与关键思路】Three Piles
 * 题目链接：https://codeforces.com/problemset/problem/2266/B
 * 标签：难度 800 | games,greedy,math
 *
 * 关键思路：只能把一堆整体加到另一堆：把三堆排序后，答案是 max(0, max - (sum - max))，即最大堆与其余两堆之差。
 * ###################################################################### */

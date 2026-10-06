#include <bits/stdc++.h>
using namespace std ;

#define int long long

int calc(int x){
    int res = 1 ;
    while(x % res == 0) res <<= 1 ;
    return (res >> 1) ;
}

void solve(){
    int w, h, n ; cin >> w >> h >> n ;
    int mx = calc(w) * calc(h) ;
    if(mx >= n) cout << "YES" ;
    else cout << "NO" ;
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
 * 【题面与关键思路】Cards for Friends
 * 题目链接：https://codeforces.com/problemset/problem/1472/A
 * 标签：难度 800 | greedy, math
 *
 * 关键思路：每次可把一个矩形切成两半，只要 w 或 h 是偶数就能继续切；答案 = 2^(w 中 2 的幂次 + h 中 2 的幂次)。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k, p ; cin >> n >> k >> p ;
    int mi = - p * n, mx = p * n ;
    if(mx < k || mi > k){
        cout << '-' << '1' ;
        return ;
    }
    k = abs(k) ;
    cout << (k + p - 1) / p ; 
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
 * 【题面与关键思路】New World, New Me, New Array
 * 题目链接：https://codeforces.com/problemset/problem/2072/A
 * 标签：难度 800 | greedy,implementation,math
 *
 * 关键思路：n 次操作后取值域是 [-p*n, p*n]，若 k 不在其中输出 -1，否则答案 = ceil(|k|/p)。
 * ###################################################################### */

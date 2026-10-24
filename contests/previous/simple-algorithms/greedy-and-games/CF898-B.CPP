#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;

    int mul = 1 ;
    int zero = 0 ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        zero += (a[t] == 0) ;
    }
    for(int t = 1 ; t <= n ; ++t) {
        if(a[t]) mul *= a[t] ;
    }
    //zero judge
    if(zero >= 2) {
        cout << 0 ;
        return ;
    }if(zero == 1){
        cout << mul ;
        return ;
    }
    int mx = -1 ; 
    for(int t = 1 ; t <= n ; ++t){
        int cur = mul / a[t] * (a[t] + 1) ;
        mx = max(mx, cur) ;
    } 
    cout << mx ;
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
 * 【题面与关键思路】Good Kid
 * 题目链接：https://codeforces.com/problemset/problem/1873/B
 * 标签：难度 800 | brute force,greedy,math
 *
 * 关键思路：给某个数加 1 使总乘积最大：若有 0 则给一个 0 加 1，否则给最小值加 1。
 * ###################################################################### */

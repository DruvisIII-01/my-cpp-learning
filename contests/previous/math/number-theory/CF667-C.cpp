#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, x, y ; cin >> n >> x >> y ;
    int D = y - x ;
    vector <int> yin ;
    for(int i = 1 ; i * i <= D ; i++){
        if(D % i == 0){
            yin.push_back(i) ;
            if(i * i < D) yin.push_back(D / i) ;
        }
    }sort(yin.begin(), yin.end()) ;
    for(auto d : yin){
        if(1 + D / d > n) continue ;
        if(y / d >= n) {
            for(int i = n - 1 ; i >= 0 ; i--){
                cout << y - i * d << ' ' ;
            }return ;
        }else{
            if(y % d == 0){
                for(int i = 1 ; i <= n ; i++){
                    cout << i * d << ' ' ;
                }return ;
            }
            for(int i = 0 ; i < n ; i++){
                cout << i * d + y % d << ' ' ;
            }return ;
        }
    }
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
 * 【题面与关键思路】Yet Another Array Restoration
 * 题目链接：https://codeforces.com/problemset/problem/1409/C
 * 标签：难度 1200 | brute force,math,number theory
 *
 * 关键思路：公差 d 必须整除 y-x，枚举 y-x 的约数 d，检查能否在不超过 n 项内同时容纳 x、y 并尽量小，再向前补足 n 项。
 * ###################################################################### */

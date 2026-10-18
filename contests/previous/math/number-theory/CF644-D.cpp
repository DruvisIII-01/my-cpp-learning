#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    vector <int> yin ;
    for(int i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            yin.push_back(i) ;
            if(i * i < n) yin.push_back(n / i) ;
        }
    }sort(yin.begin(), yin.end()) ;
    int sz = yin.size() ;
    for(int i = 0 ; i < sz ; i++){
        if(yin[i] > k){
            cout << n / yin[i - 1] ;
            return ;
        }
    }cout << n / yin[sz - 1] ;
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
 * 【题面与关键思路】Buying Shovels
 * 题目链接：https://codeforces.com/problemset/problem/1360/D
 * 标签：难度 1300 | math,number theory
 *
 * 关键思路：枚举 n 的约数 d（套餐数），若 d <= k 则可用 n/d 个 shovel 组成；取最大的 n/d，答案即 n/d。
 * ###################################################################### */

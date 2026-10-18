#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    int sum = 0, mi = LLONG_MAX ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        mi = min(a[i], mi) ;
        sum += a[i] ;
    }
    cout << sum - mi * n ;
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
 * 【题面与关键思路】Equal Candies
 * 题目链接：https://codeforces.com/problemset/problem/1676/B
 * 标签：难度 800 | greedy,math,sortings
 *
 * 关键思路：答案 = sum(a) - n * min(a)：把所有盒子补到最小值即可。
 * ###################################################################### */

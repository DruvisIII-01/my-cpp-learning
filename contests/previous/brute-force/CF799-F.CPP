#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    vector <int> cnt(10) ; 
    for(int i = 1 ; i <= n ; ++i) {
        cin >> a[i] ;
        a[i] %= 10 ;
        cnt[a[i]]++ ;
        if(cnt[a[i]] > 3) cnt[a[i]] = 3 ;
    }//3
    for(int i = 0 ; i <= 9 ; ++i){
        if(!cnt[i]) continue ;
        cnt[i]-- ;
        for(int j = 0 ; j <= 9 ; j++){
            if(!cnt[j] || i + j > 3) continue ;
            cnt[j]-- ;
            if(cnt[3 - i - j]) {
                cout << "YES" ;
                return ;
            }cnt[j]++ ;
        }
        cnt[i]++ ;
    }
    for(int i = 0 ; i <= 9 ; ++i){
        if(!cnt[i]) continue ;
        cnt[i]-- ;
        for(int j = 0 ; j <= 9 ; j++){
            if(!cnt[j] || i + j > 13
            ||i + j < 4) continue ;
            cnt[j]-- ;
            if(cnt[13 - i - j]) {
                cout << "YES" ;
                return ;
            }cnt[j]++ ;
        }
        cnt[i]++ ;
    }//23
    for(int i = 0 ; i <= 9 ; ++i){
        if(!cnt[i]) continue ;
        cnt[i]-- ;
        for(int j = 0 ; j <= 9 ; j++){
            if(!cnt[j] || i + j < 14) continue ;
            cnt[j]-- ;
            if(cnt[23 - i - j]) {
                cout << "YES" ;
                return ;
            }cnt[j]++ ;
        }
        cnt[i]++ ;
    }cout << "NO" ;
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
 * 【题面与关键思路】3SUM
 * 题目链接：https://codeforces.com/problemset/problem/1692/F
 * 标签：难度 1300 | brute force, math
 *
 * 关键思路：只关心三个数的和的个位是否为 3，因此按"尾数"计数且每种尾数最多留 3 个，再暴力枚举三数组合。
 * ###################################################################### */

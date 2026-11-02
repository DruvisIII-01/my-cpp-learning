#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ; 
    vector<int> a(n + 1) ;
    vector<int> hsh(n + 1) ;

    int mx = -1 ;
    for(int t = 1 ; t <= n ; ++t){
        cin >> a[t] ;
        hsh[a[t]]++ ;
        mx = max(mx, a[t]) ;
    } int tmp_mx = mx ;
    if(!(hsh[mx] % 2)){
        cout << "YES" ;
        return ;
    }

    for(int t = tmp_mx - 1 ; t >= 1 ; t--){
        if(hsh[t]){
            if(mx - t <= k) {
                cout << "YES" ;
                return ;
            }else {
                mx = t ;
                if(!(hsh[mx] % 2)){
                    cout << "YES" ;
                    return ;
                }
            }
        }
    }
    cout << "NO" ;
    return ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】Brand New Tatar TV Show
 * 题目链接：https://codeforces.com/problemset/problem/2236/D
 * 标签：难度 1300 | binary search, constructive, dp, games, math
 *
 * 关键思路：统计每个值的出现次数，从最大值往下扫：若最大值的次数为偶数则 YES；否则找下一个出现过的值 t，若 mx−t ≤ k 则 YES，并把 mx 改成 t 继续。
 * ################################################################## */

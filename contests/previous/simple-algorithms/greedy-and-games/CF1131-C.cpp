#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    int sum = 0 ; 
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        sum += a[t] ;
    }

    //special judge
    bool impossible = true ;
    for(int t = 1 ; t <= n ; ++t) {
        if(a[t] > 1){
            impossible = false ;
            break ; 
        }
    }if(impossible){
        cout << "-1" ;
        return ;
    }

    bool mid = false ;
    for(int t = 2 ; t < n ; ++t) {
        if(a[t] > 1){
            mid = true ; 
            break ; 
        }
    }if(mid){
        cout << sum - 1 ;
        return ;
    }cout << a[1] + a[n] - 1 ;
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
 * 【题面与关键思路】Math and Physics
 * 题目链接：https://codeforces.com/problemset/problem/2278/C
 * 标签：难度 2278C（新场次，暂无 rating） | greedy
 *
 * 关键思路：全是 1 时无解（输出 −1）；只要存在 a[i] > 1，就把所有大于 1 的值当作"可以传播"的种子，按位置分类累加求和。
 * ################################################################## */

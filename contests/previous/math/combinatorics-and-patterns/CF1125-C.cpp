#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    map<int, int> cnt ;
    vector<int> vis ; 
    vector<int> v(n + 1) ;
    for(int t = 1 ; t <= n - 4 ; ++t) {
        int val = a[t] + a[t + 2] - a[t + 4] ;
        v[t] = val ;
        if(!cnt[val]) vis.push_back(val) ;
        cnt[val]++ ; 
    }
    //for(int x : vis) cout << x << ' ' << cnt[x] << endl ; 

    int ans = 0 ;
    vector<int> dt(4) ; dt = {-4, -2, 2, 4} ;
    for(int t = 1 ; t <= n - 4 ; ++t){
        int val = v[t], tmp = cnt[val] ;
        for(int i = 0 ; i < 4 ; ++i){
            int nt = t + dt[i] ;
            if(nt < 1 || nt > n - 4) continue ;
            if(v[nt] == val) tmp-- ;
        }
        ans += tmp - 1 ;
    }
    cout << ans / 2 ;
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
 * 【题面与关键思路】Unrequited Love
 * 题目链接：https://codeforces.com/problemset/problem/2275/C
 * 标签：难度 1000 | brute force, data structures
 *
 * 关键思路：对每个长度为 5 的窗口计算特征值 `a[i]+a[i+2]−a[i+4]`，用 map 统计相同特征值的出现次数，再扣除相邻窗口的重复计数后除以 2。
 * ################################################################## */

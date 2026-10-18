#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define pii pair<int, int>

const int inff = 1e9 + 7 ;

int isqrt(int x){
    int res = x ; 
    while(res){
        res-- ;
        if(res * res <= x) return res ;
    }return res ;
}
void solve(){
    int n, m ; cin >> n >> m ;
    vector<int> x(n + 1) ;for(int i = 1 ; i <= n ; ++i) cin >> x[i] ;
    vector<int> r(n + 1) ;for(int i = 1 ; i <= n ; ++i) cin >> r[i] ;
    map<int, int> mp ;

    for(int i = 1 ; i <= n ; ++i){
        for(int j = x[i] - r[i] ; j <= x[i] + r[i] ; j++){
            int y = (int)sqrt(r[i] * r[i] - (j - x[i]) * (j - x[i])) ;
            mp[j] = max(mp[j], 2 * y + 1) ;
        }
    }

    int ans = 0 ; for(auto [x, c] : mp) ans += c ;
    cout << ans ;
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
 * 【题面与关键思路】Counting Points
 * 题目链接：https://codeforces.com/problemset/problem/2074/D
 * 标签：难度 1400 | brute force,data structures,geometry,implementation,two pointers
 *
 * 关键思路：枚举每个圆覆盖的横坐标 j，算出纵坐标范围长度 2*sqrt(r^2-(j-x)^2)+1，用 map 对每个 x 取所有圆的最大高度，最后按列求和。关键是避免浮点误差（整数开方）。
 * ###################################################################### */

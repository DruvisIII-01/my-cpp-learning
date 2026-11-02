#include <bits/stdc++.h>
using namespace std ;

#define int long long
void P(vector<int>&a){
    cout << "===========" << endl ;
    for(int i = 1 ; i < a.size() ; ++i) cout << a[i] << ' ' ;
    cout << endl << "===========" << endl ;
}

void solve(){
    int n, c, d ; cin >> n >> c >> d ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; t++) cin >> a[t] ;

    sort(a.begin() + 1, a.end(), greater<int>()) ;
    vector<int> pre(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) pre[t] = pre[t - 1] + a[t] ;
    // P(a) ;
    // P(pre) ;

    //special-judge
    if(a[1] * d < c){
        cout << "Impossible" ;
        return ;
    }if(pre[min(n, d)] >= c){
        cout << "Infinity" ;
        return ;
    }

    int ans = -1 ;
    for(int k = d - 1 ; k >= 0 ; k--){
        int one = pre[min(k + 1, n)] ;
        int turns = d / (k + 1), rest = d % (k + 1) ;
        int coins = one * turns + pre[min(rest, n)] ;
        if(coins >= c){
            ans = k ;
            break ;
        }
    }cout << ans ;
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
 * 【题面与关键思路】Quests
 * 题目链接：https://codeforces.com/problemset/problem/1760/F
 * 标签：难度 1500 | binary search, greedy, sortings
 *
 * 关键思路：降序排序求前缀和，二分"周期长度 k"，check 用前缀和 O(1) 算出 d 天内能获得的最大值；不满足输出 Impossible/Infinity。
 * ################################################################## */

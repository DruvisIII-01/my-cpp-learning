#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ;
    vector<vector<int>> a(n + 1, vector<int>(m + 1)) ;
    vector<int> mi(n + 1) ;
    vector<int> order(n * m + 1) ;
    for(int t = 1 ; t <= n ; ++t){
        mi[t] = m * n * 2 ;
        for(int i = 1 ; i <= m ; ++i){
            cin >> a[t][i] ;
            mi[t] = min(mi[t], a[t][i]) ;
        }order[mi[t]] = t ;
    }//for(int t = 1 ; t <= n ; ++t) cout << mi[t] << ' ' ;

    sort(mi.begin() + 1, mi.end()) ;
    bool ans = true ;
    for(int t = 1 ; t <= n ; ++t) {
        int tar = order[mi[t]] ;
        for(int i = 1 ; i <= m ; ++i){
            if((a[tar][i] - mi[t]) % n != 0
              || a[tar][i] > mi[t] + (m - 1) * n){
                ans = false ;
                break ;
            }
        }if(!ans) break ;
    }if(!ans) cout << "-1" ;
    else for(int t = 1 ; t <= n ; ++t) cout << order[mi[t]] << ' ' ;
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
 * 【题面与关键思路】Farmer John's Card Game
 * 题目链接：https://codeforces.com/problemset/problem/2060/B
 * 标签：难度 1000 | greedy, sortings
 *
 * 关键思路：每头牛的牌必须按"最小值 + j·n"排列（j=0..m−1）。先取每行的最小值作为该牛的"第一张牌"，按最小值升序排序得到出牌顺序 p；再校验每头牛的牌是否都满足 (a−min) % n == 0 且 a ≤ min+(m−1)·n，不满足输出 −1。
 * ################################################################## */

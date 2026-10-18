#include <bits/stdc++.h>
using namespace std ;

#define int long long

int mp[111][111] ;

void solve(){
    int n ; cin >> n ;
    memset(mp, 0, sizeof(mp)) ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            char ch ; cin >> ch ;
            mp[i][j] = ch - '0' ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(j == n || i == n) continue ;
            if(mp[i][j]){
                if(!mp[i + 1][j] && !mp[i][j + 1]){
                    cout << "NO" ;
                    return ;
                }
            }
        }
    }cout << "YES" ;
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
 * 【题面与关键思路】Polygon
 * 题目链接：https://codeforces.com/problemset/problem/1360/E
 * 标签：难度 1300 | dp,graphs,implementation,shortest paths
 *
 * 关键思路：检查 n×n 的 01 网格中每个 1 的右邻与下邻是否也为 1（即是否为合法"多边形"填充），纯细节判定。
 * ###################################################################### */

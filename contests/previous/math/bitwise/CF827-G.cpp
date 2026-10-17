#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    int mx = 1 ; int lst = 0 ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        lst |= a[t] ;
    }

    vector<bool> vis(n + 1) ; 
    vector<int> ans ;
    int Or = 0 ;
    while(lst != Or){
        int M = 0 ;
        int Mi = -1 ;
        for(int i = 1 ; i <= n ; i++){
            if( ((a[i] | Or) > (M | Or)) && (!vis[i])){
                M = a[i] ;
                Mi = i ;
            }
        }
        Or |= M ;
        ans.push_back(M) ;
        vis[Mi] = true ;
    }
    for(int t = 1 ; t <= n ; ++t){
        if(!vis[t]) ans.push_back(a[t]) ; 
    }for(int x : ans) cout << x << ' ' ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
/* ######################################################################
 * 【题面与关键思路】Orray
 * 题目链接：https://codeforces.com/problemset/problem/1742/G
 * 标签：难度 1500 | bitmasks, brute force, constructive algorithms, greedy
 *
 * 关键思路：目标是让前缀 OR 序列的字典序最大：每次贪心地从未选的数中挑"与当前 OR 相或后值最大"的那个，直到 OR 不再变化，剩下的数任意接在后面。按位贪心 + 少量枚举的经典套路。
 * ###################################################################### */

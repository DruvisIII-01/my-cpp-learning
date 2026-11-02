#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ; 
    vector<int> a(n + 1) ;
    map<int, int> cnt ;
    vector<int> vis ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        if(!cnt[a[t]]) vis.push_back(a[t]) ;
        cnt[a[t]]++ ;
    }
    int same = 0, diff = 0 ;
    for(int x : vis){
        if(x + x == k) same += cnt[x] / 2 ;
        else diff += min(cnt[x], cnt[k - x]) ;
    }cout << same + diff / 2 ;
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
 * 【题面与关键思路】Game of Mathletes
 * 题目链接：https://codeforces.com/problemset/problem/2060/C
 * 标签：难度 900 | games, greedy, sortings, two pointers
 *
 * 关键思路：用 map 统计频次。对每个出现的 x：若 2x == k 则贡献 cnt[x]/2；否则累计 min(cnt[x], cnt[k−x])，最后整体除以 2（每对算了两次）。
 * ################################################################## */

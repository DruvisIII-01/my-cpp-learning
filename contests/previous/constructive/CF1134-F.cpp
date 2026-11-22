#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1), b(n + 1) ;
    map<int, int> id ; 
    for(int t = 1 ; t <= n ; ++t) cin >> b[t] ;
    for(int t = 1 ; t <= n ; ++t) id[t] = b[t] + n + 1 - t ;
    
    bool ans = true ;
    for(int t = 1 ; t <= n ; ++t) {
        if(id[t] > n || id[t] <= 0) {
            ans =  false ;
            break ;
        }if(!a[id[t]]) a[id[t]] = t ;
        else {
            ans = false ;
            break ; 
        }
    }if(ans) for(int t = 1 ; t <= n ; ++t) cout << a[t] << ' ' ;
    else cout << "-1" ;
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
 * 【题面与关键思路】Value Counters
 * 题目链接：https://codeforces.com/problemset/problem/2290/F
 * 标签：难度 2290F（新场次，暂无 rating） | binary search, constructive, math
 *
 * 关键思路：构造排列 a 使 a[t] + b[t] + (n+1−t) 互不相同：令 id[t] = b[t] + n + 1 − t，把它当"位置编号"，若所有 id 落在 1..n 且互不相同则取逆排列输出，否则 −1。
 * ################################################################## */

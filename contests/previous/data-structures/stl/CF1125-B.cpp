#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ; s = '*' + s ;
    stack<int> scanned ; 
    vector<int> vis(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) {
        if(s[t] == '1') scanned.push(t) ;
        else if(s[t] == '2'){
            if(scanned.empty()) vis[t] = true ;
            else {
                int tp = scanned.top() ;
                scanned.pop() ;
                vis[tp] = true ;
            }
        }else vis[t] = true ;
    }

    int ans = 0 ;
    for(int t = 1 ; t <= n ; ++t) ans += !vis[t] ;
    cout << ans << endl ;
    for(int t = 1 ; t <= n ; ++t) 
    if(!vis[t]) cout << t << ' ' ;
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
 * 【题面与关键思路】Did Not Go to Print
 * 题目链接：https://codeforces.com/problemset/problem/2275/B
 * 标签：难度 800 | data structures, implementation
 *
 * 关键思路：用栈维护未配对的 1：遇到 2 就弹出最近的一个 1（配成一对），最后没配上的位置就是需要删除的下标。
 * ################################################################## */

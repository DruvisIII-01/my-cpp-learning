#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    int un = 1 ;
    vector<bool> vis(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) vis[a[t]] = true ;
    stack<int> stk ;
    for(int t = 1 ; t <= n ; ++t) if(!vis[t]) stk.push(t) ;
    for(int t = 1 ; t <= n ; ++t) vis[t] = false ;

    for(int t = 1 ; t <= n ; ++t){
        if(!vis[a[t]]){
            vis[a[t]] = true ;
            cout << a[t] << ' ' ;
        }else{
            int tp = stk.top() ;
            cout << tp << ' ' ;
            stk.pop() ;
        }
    }
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
 * 【题面与关键思路】Harder Problem
 * 题目链接：https://codeforces.com/problemset/problem/2044/D
 * 标签：难度 1100 | constructive algorithms,greedy,math
 *
 * 关键思路：输出一个排列，使其与给定序列 a 在"每个值首次出现的位置"上一致。做法：先标记 a 中出现过的值，把没用到的值压栈；逐位扫描 a，该值首次出现就保留，否则用栈顶的未用值替换。
 * ###################################################################### */

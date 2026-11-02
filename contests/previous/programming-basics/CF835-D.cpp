#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a ;
    for(int t = 1 ; t <= n ; ++t){
        int x ; cin >> x ; 
        if(a.empty() || a[a.size() - 1] != x) a.push_back(x) ;
    }if(a.size() == 1){
        cout << "YES" ;
        return ;
    }

    int cnt = 0 ;
    for(int t = 0 ; t < a.size() ; ++t){
        if(t == 0) cnt += (a[t] < a[t + 1]) ;
        else if(t == a.size() - 1) cnt += (a[t] < a[t - 1]) ;
        else cnt += (a[t] < a[t + 1]) && (a[t] < a[t - 1]) ;
    }
    if(cnt == 1) cout << "YES" ;
    else cout << "NO" ;
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
 * 【题面与关键思路】Challenging Valleys
 * 题目链接：https://codeforces.com/problemset/problem/1760/D
 * 标签：难度 1000 | implementation, two pointers
 *
 * 关键思路：先去重相邻相等元素，再数"局部谷"的个数；恰好 1 个则 YES（首/尾单独判）。
 * ################################################################## */

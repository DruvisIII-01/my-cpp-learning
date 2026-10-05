#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    int cnt1 = 0 ;
    int cnt2 = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
        cnt1 += (a[i] == 1) ;
        cnt2 += (a[i] == 2) ;
    }
    if(cnt1 % 2 == 0 && cnt2 % 2 == 0) cout << "YES" ;
    else if(cnt1 % 2 == 0 && cnt2 % 2 == 1){
        if(cnt1 > 0) cout << "YES" ;
        else cout << "NO" ;
    }else cout << "NO" ;
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
 * 【题面与关键思路】Long Jumps
 * 题目链接：https://codeforces.com/problemset/problem/1472/C
 * 标签：难度 1100 | dp, graphs
 *
 * 关键思路：从每个起点 i 出发按 i + a[i] 跳转，求路径上 a 之和的最大值；带 vis 剪枝的枚举，每个点最多访问一次，O(n)。
 * ###################################################################### */

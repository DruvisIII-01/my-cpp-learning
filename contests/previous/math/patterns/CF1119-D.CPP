#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    int cnt0 = 0 ;
    for(int i = 1 ; i <= n ; ++i) cnt0 += (a[i] == 0) ;

    if(!cnt0){
        cout << "YES" << endl ;
        for(int i = 1 ; i <= n ; ++i) cout << 'A' ;
    }else if(cnt0 == 1) cout << "NO" ;
    else {
        cout << "YES" << endl ;
        bool first = false ;
        for(int i = 1 ; i <= n ; ++i){
            if(a[i] > 0 ) cout << 'C' ;
            else{
                if(!first){
                    cout << 'A' ;
                    first = true ;
                }else cout << 'B' ;
            }
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
 * 【题面与关键思路】MEX Multiset
 * 题目链接：https://codeforces.com/problemset/problem/2259/D
 * 标签：难度 1200 | constructive algorithms, greedy
 *
 * 关键思路：答案由 0 的个数决定：cnt0 = max(0, k-m+1) 个 0 必须出现，剩下的值插到区间两端使 MEX 最小；分类讨论输出。
 * ###################################################################### */

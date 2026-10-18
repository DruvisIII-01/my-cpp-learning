#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    if(n == 1){
        cout << "YES" ;
        return ;
    }bool ans = true ;
    sort(a.begin() + 1, a.begin() + n + 1) ;
    for(int i = 2 ; i <= n ; i++){
        if(a[i] > a[i - 1] + 1){
            ans = false ;
            break ;
        }
    }if(ans) cout << "YES" ;
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

/* ######################################################################
 * 【题面与关键思路】Remove Smallest
 * 题目链接：https://codeforces.com/problemset/problem/1399/A
 * 标签：难度 800 | greedy,sortings
 *
 * 关键思路：排序后若存在相邻差 > 1 就不可能全部消掉，否则 YES。
 * ###################################################################### */

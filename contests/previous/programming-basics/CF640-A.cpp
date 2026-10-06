#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    int base = 1 ;
    vector <int> ans ;
    do{
        int c = n%10 ;
        if(c != 0) ans.push_back(c*base) ;
        n = n/10 ;
        base = base*10 ;
    }while(n != 0) ;
    cout << ans.size() << endl ;
    for(auto x : ans) cout << x << ' ' ;
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
 * 【题面与关键思路】Sum of Round Numbers
 * 题目链接：https://codeforces.com/problemset/problem/1352/A
 * 标签：难度 800 | implementation, math
 *
 * 关键思路：按十进制位拆出所有非零位，每个非零位构成一个 round number，输出个数与各数。
 * ###################################################################### */

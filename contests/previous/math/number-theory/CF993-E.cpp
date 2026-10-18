// l2 / r1 <= q <= r2 / l1
// Q[K] // k 100 
// let q0 = Q[0]
// [l1, r1] intersects [l2 / q0, r2 / q0]
#include <bits/stdc++.h>
using namespace std ;

#define int long long
const double eps = 1e-6 ;

void solve(){
    int k, l1, r1, l2, r2 ; cin >> k >> l1 >> r1 >> l2 >> r2 ;
    vector<int> Q ; 
    int power = 1 ;
    if(power * r1 >= l2 && power * l1 <= r2) Q.push_back(power) ;
    for(int t = 1 ; t <= 32 ; t++){
        power *= k ;
        if(power * r1 >= l2 && power * l1 <= r2) Q.push_back(power) ;
        if(power * l1 > r2) break ;
    }
    //for(int q : Q) cout << q << endl ;
    
    int ans = 0 ;
    for(int q : Q){
        int nl2 = (l2 + q - eps) / q ; int nr2 = r2 / q ;
        //cout << nl2 << ' ' << nr2 << endl ;
        ans += (min(nr2, r1) - max(nl2, l1)) + 1 ;
    }cout << ans ;
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
 * 【题面与关键思路】Insane Problem
 * 题目链接：https://codeforces.com/problemset/problem/2044/E
 * 标签：难度 1300 | binary search,greedy,implementation,math,number theory
 *
 * 关键思路：要数 (x, y) 满足 l1 ≤ x ≤ r1、l2 ≤ y ≤ r2 且 y/x = k^t。枚举所有在值域内可能用到的 k 的幂 q（q·l1 > r2 就停），对每个 q 求 x 的合法区间 [⌈l2/q⌉, ⌊r2/q⌋] 与 [l1, r1] 的交集长度再累加。
 * ###################################################################### */

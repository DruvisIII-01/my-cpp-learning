#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<int> mx(1005) ;
    for(int t = 1 ; t <= n ; ++t){
        int z ; cin >> z ;
        mx[z] = max(mx[z], t) ;
    } 
    int ans = -1 ;
    for(int i = 1 ; i <= 1000 ; ++i){
        for(int j = 1 ; j <= 1000 ; ++j){
            if(__gcd(i, j) == 1 && mx[i] && mx[j])
            ans = max(ans, mx[i] + mx[j]) ;
        }
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
 * 【题面与关键思路】Coprime
 * 题目链接：https://codeforces.com/problemset/problem/1742/D
 * 标签：难度 1100 | brute force, math, number theory
 *
 * 关键思路：要最大化 i+j 使得 a[i] 与 a[j] 互质。用 mx[v] 记录值 v 出现的最大下标，然后 O(1000²) 枚举值域内的所有 (i, j)，gcd(i,j)==1 且两者都出现过时更新答案，避免 O(n²)。
 * ###################################################################### */

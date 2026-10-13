#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    vector <int> cnt (31) ;
    int ans = a[1] ;
    for(int i = 1 ; i <= n ; i++) {
        ans &= a[i] ;
        int bt = 1 ;
        for(int t = 0 ; t < 31 ; t++){
            cnt[t] += ((bt & a[i]) == 0) ;
            bt <<= 1 ;
        }
    }
    //for(int i = 0 ; i < 31 ; i++) cout << cnt[i] << ' ' ;
    //cout << endl ;
    //for(int i = 0 ; i < 31 ; i++) if(cnt[i] > k) cnt[i] = -1 ;
    int bt = (int) 1 << 30 ;
    //int sum = 0 ;
    for(int t = 30 ; t >= 0 ; t--){
        if(!cnt[t] || cnt[t] > k) bt >>= 1 ;
        else {
            k -= cnt[t] ;
            if(k < 0) break ;
            else ans |= bt ;
            bt >>= 1 ;
        }
    }
    cout << ans ;
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
 * 【题面与关键思路】Maximal AND
 * 题目链接：https://codeforces.com/problemset/problem/1669/H
 * 标签：难度 1300 | bitmasks, greedy, math
 *
 * 关键思路：从高位到低位贪心：统计该位为 0 的元素个数 c，若剩余操作数 k ≥ c 就置位并消耗 c，答案按位累加。
 *
 * 题号备注：本题属于 **Codeforces Round 784 (Div. 4)，contestId 1669**（2022-04-21）。
 *    早期文件名写成 CF786 是笔误（官方 Round 786 是 Div.3，题目完全不同），现已改名为 CF784。
 * ###################################################################### */

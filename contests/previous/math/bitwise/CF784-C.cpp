#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    bool odd1 = true, even1 = true ;
    int x1 = a[1] % 2, x2 = a[2] % 2 ;
    for(int i = 3 ; i <= n ; i++){
        int xi = a[i] % 2 ;
        if(i % 2 == 1) {
            if(xi != x1) {
                odd1 = false ;
                break ;
            }
        }else {
            if(xi != x2) {
                even1 = false ;
                break ;
            }
        }
    }
    if(even1 && odd1) cout << "YES" ;
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
 * 【题面与关键思路】Odd/Even Increments
 * 题目链接：https://codeforces.com/problemset/problem/1669/C
 * 标签：难度 800 | greedy,implementation,math
 *
 * 关键思路：每次操作给同奇偶位置全体加 1；只需判断奇数位之间是否同奇偶、偶数位之间是否同奇偶。
 *
 * 题号备注：本题属于 **Codeforces Round 784 (Div. 4)，contestId 1669**（2022-04-21）。
 *    早期文件名写成 CF786 是笔误（官方 Round 786 是 Div.3，题目完全不同），现已改名为 CF784。
 * ###################################################################### */

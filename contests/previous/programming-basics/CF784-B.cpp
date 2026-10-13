#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    vector <int> hsh(n + 1) ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
        hsh[a[i]]++ ;
    }
    for(int i = 1 ; i <= n ; i++) {
        if(hsh[i] >= 3) {
            cout << i ;
            return ;
        }
    }
    cout << '-' << 1 ;
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
 * 【题面与关键思路】Triple
 * 题目链接：https://codeforces.com/problemset/problem/1669/B
 * 标签：难度 800 | implementation, sortings
 *
 * 关键思路：桶计数后顺序扫描，输出第一个出现次数 ≥ 3 的数（不存在输出 −1）。
 *
 * 题号备注：本题属于 **Codeforces Round 784 (Div. 4)，contestId 1669**（2022-04-21）。
 *    早期文件名写成 CF786 是笔误（官方 Round 786 是 Div.3，题目完全不同），现已改名为 CF784。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void Printg (int time, int value){
    for(int i = 1 ; i <= time ; i++) cout << value ;
}

void solve(){
    int n0, n1, n2 ; cin >> n0 >> n1 >> n2 ;
    if(n1 == 0){
        if(n2 > 0) {
            Printg(n2 + 1, 1) ;
            return ;
        }
        if(n0 > 0) {
            Printg(n0 + 1, 0) ;
            return ;
        }
    }
    Printg(n2 + 1, 1) ;
    Printg(n0 + 1, 0) ;
    if(n1 % 2 == 1) Printg((n1 - 1) / 2, 10) ;
    else {
        Printg(n1 / 2 - 1, 10) ;
        cout << 1 ;
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
 * 【题面与关键思路】Binary String Reconstruction
 * 题目链接：https://codeforces.com/problemset/problem/1352/F
 * 标签：难度 1500 | constructive algorithms,dfs and similar,math
 *
 * 关键思路：把 n0 个 0 与 n2 个 2 转成"0/1 交替块"，n1 个 1 单独成段，按 n1==0、n2==0 等边界分类拼接输出。
 * ###################################################################### */

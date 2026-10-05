#include <bits/stdc++.h>
using namespace std ;

#define int long long

void Prt4(int n0){
    for(int t = 1 ; t <= n0 / 4 ; t++){
            int mt = 4 * t ;
            cout << mt - 2 << ' ' << mt << ' ' 
            << mt - 3 << ' ' << mt - 1 << ' ' ; 
        }
}

void solve(){
    int n ; cin >> n ;
    if(n <= 3) {
        cout << '-' << '1' ;
        return ;
    }
    if(n % 4 == 0) Prt4(n) ;
    else if(n % 4 == 1){
        Prt4(n - 1) ;
        cout << n ;
    }else if(n % 4 == 2){
        Prt4(n - 2 - 4) ;
        int m = n - 2 ;
        cout << m - 2 << ' ' << m + 2 << ' ' 
        << m << ' ' << m - 3 << ' ' << m - 1 << ' ' 
        << m + 1 ;
    }else {
        Prt4(n - 3 - 4) ;
        int m = n - 3 ;
        cout << m - 2 << ' ' << m + 2 << ' ' 
        << m << ' ' << m - 3 << ' ' << m - 1 << ' ' 
        << m + 1 << ' ' << m + 3;
    }
    //2 4 1 3 6 8 5 7 10 12 9 11 4n-2 4n+2 4n 4n-3 4n-1 4n+1 // 4n+3  
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
 * 【题面与关键思路】Special Permutation
 * 题目链接：https://codeforces.com/problemset/problem/1352/G
 * 标签：难度 1600 | constructive algorithms
 *
 * 关键思路：构造相邻差在 [2,4] 的排列：按 n mod 4 分块，每块输出 (4t-2, 4t, 4t-3, 4t-1) 之类，注意小块 n<=3 无解。
 * ###################################################################### */

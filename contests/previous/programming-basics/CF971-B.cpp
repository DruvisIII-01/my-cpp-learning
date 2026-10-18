#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <string> ss(n + 1) ;
    for(int i = 1 ; i <= n ; i++){
        cin >> ss[i] ;
        ss[i] = '*' + ss[i] ;
    }for(int i = n ; i >= 1 ; i--){
        for(int j = 1 ; j <= 4 ; j++){
            if(ss[i][j] == '#') {
                cout << j << ' ' ;
                break ;
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
 * 【题面与关键思路】osu!mania
 * 题目链接：https://codeforces.com/problemset/problem/2009/B
 * 标签：难度 800 | brute force,implementation
 *
 * 关键思路：从下往上逐行读取，输出每行井号所在的列号。
 * ###################################################################### */

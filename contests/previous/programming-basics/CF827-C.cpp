#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    vector<vector<int>> a(9, vector<int>(9)) ;
    for(int t = 1 ; t <= 8 ; ++t){
        string s ; cin >> s ; s = ' ' + s ;
        for(int i = 1 ; i <= 8 ; ++i){
            if(s[i] == 'R') a[t][i] = 1 ;
            else if(s[i] == 'B') a[t][i] = -1 ;
        }
    }
    char ans = '*' ;

    for(int i = 1 ; i <= 8 ; ++i){
        int find_R = true ;
        for(int j = 1 ; j <= 8 ; ++j){
            if(a[i][j] != 1){
                find_R = false ;
                break ;
            }
        }
        if(find_R) {
            ans = 'R' ;
            break ;
        }
    }
    for(int j = 1 ; j <= 8 ; ++j){
        int find_B = true ;
        for(int i = 1 ; i <= 8 ; ++i){
            if(a[i][j] != -1){
                find_B = false ;
                break ;
            }
        }
        if(find_B){
            ans = 'B' ;
            break ;
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
 * 【题面与关键思路】Stripes
 * 题目链接：https://codeforces.com/problemset/problem/1742/C
 * 标签：难度 900 | implementation
 *
 * 关键思路：8×8 棋盘上判断最后画的是 R 还是 B：找是否存在整行全为 R（答案是 R），否则找是否存在整列全为 B（答案是 B）。
 * ###################################################################### */

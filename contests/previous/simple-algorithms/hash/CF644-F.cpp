#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ; 
    vector <string> ss(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> ss[i] ;
    string ans = ss[1] ;
    for(int t = 0 ; t < m ; t++){
        string org = ans ;
        for(int i = 0 ; i < 26 ; i++){
            char ch = 'a' + i ;
            ans[t] = ch ;
            bool ok = true ;
            for(int j = 2 ; j <= n ; j++){
                int diff = 0 ;
                for(int k = 0 ; k < m ; k++){
                    if(ss[j][k] != ans[k]) diff++ ;
                }if(diff >= 2){
                    ok = false ; 
                    break ;
                }
            }if(ok) {
                cout << ans ;
                return ;
            }
        }
        ans = org ;
    }cout << '-' << 1 ;
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
 * 【题面与关键思路】Spy-string
 * 题目链接：https://codeforces.com/problemset/problem/1360/F
 * 标签：难度 1700 | bitmasks,brute force,constructive algorithms,dp,hashing,strings
 *
 * 关键思路：对每个位置、每个字符尝试替换（26*m 种），检查替换后的串与其它所有串的汉明距离是否 <= 1；可行即输出，否则 -1。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int q ; cin >> q ; 
    int AofS = 1 ; int AofT = 1 ;
    bool must_yes = false ;
    bool s_has_other = false ;

    for(int t = 1 ; t <= q ; ++t){
        int op, k ; string s ;
        cin >> op >> k >> s ;
        for(char ch : s) {
            if(ch > 'a') {
                if(op == 2) must_yes = true ;
                else s_has_other = true ;
            }else {
                if(op == 2) AofT += k ;
                else AofS += k ;
            }
        }if(must_yes) cout << "YES" << '\n' ;
        else if(s_has_other) cout << "NO" << '\n' ;
        else {
            if(AofS >= AofT) cout << "NO" << '\n' ;
            else cout << "YES" << '\n' ;
        }
    }
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
    }
    return 0;
}
/* ######################################################################
 * 【题面与关键思路】Smaller
 * 题目链接：https://codeforces.com/problemset/problem/1742/F
 * 标签：难度 1500 | greedy, implementation, strings
 *
 * 关键思路：维护四个量：s、t 中字母 a 的个数与"非 a 字符"是否存在。若 t 中出现非 a 字符则一定 YES（可以把它放最前）；若 s 出现非 a 字符而 t 没有则 NO；否则比较 a 的个数。
 * ###################################################################### */

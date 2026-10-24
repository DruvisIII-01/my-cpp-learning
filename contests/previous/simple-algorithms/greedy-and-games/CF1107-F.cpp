#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ; s = '*' + s ;

    int fi = n + 1 ; 
    bool find_fi = false ;
    for(int t = 1 ; t <= n ; ++t){
        if(s[t] == '1'){
            fi = t ; 
            find_fi = true ;
            break ;
        }
    }int ls = n + 1 ;
    bool find_ls = false ;
    for(int t = n ; t >= 1 ; t--){
        if(s[t] == '0'){
            ls = t ;
            find_ls = true ;
            break ;
        }
    }
    //cout << fi << ' ' << ls << endl ;
    if(!find_fi || !find_ls){
        cout << "Bob" ;
        return ;
    }

    int an = fi ;
    int cur = 0 ;
    bool Alice = false ;
    for(int i = fi ; i <= ls ; ++i){
        if(s[i] == s[an]) cur++ ;
        else {
            if(cur % 2){
                Alice = true ;
                break ;
            }
            an = i ;
            cur = 1 ;
        }if(i == ls && cur % 2) Alice = true ;
    }
    if(Alice) cout << "Alice" ;
    else cout << "Bob" ;
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
 * 【题面与关键思路】A Bit Odd
 * 题目链接：https://codeforces.com/problemset/problem/2241/F
 * 标签：难度 1700 | data structures,games,greedy,math
 *
 * 关键思路：Alice 与 Bob 在 01 串上博弈。先找第一个 1 的下标 fi 与最后一个 0 的下标 ls；若不存在其一，Bob 胜。否则只需看 [fi, ls] 内每段连续相同字符的长度是否全为偶数：出现奇数长度则 Alice 胜，否则 Bob 胜。
 * ###################################################################### */

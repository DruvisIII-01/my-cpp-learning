#include <bits/stdc++.h>
using namespace std ;

#define int long long

//ub

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;
    s = s + 'W' ;
    bool cnt[2] = {0};
    for(char ch : s){
        if(ch == 'W') {
            if ((!cnt[1] && cnt[0]) || (!cnt[0] && cnt[1] )){
                cout << "NO" ;
                return ;
            }
            cnt[1] = 0 ;
            cnt[0] = 0 ;
        }
        else if(ch == 'R') {
            cnt[1] = 1 ;
        }else cnt[0] = 1 ;
    }
    cout << "YES" ;
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
 * 【题面与关键思路】Colorful Stamp
 * 题目链接：https://codeforces.com/problemset/problem/1669/D
 * 标签：难度 1100 | implementation
 *
 * 关键思路：按字符 W 分段（W 是分隔符），每段内 R 与 G 若只出现一种则非法，逐段判定输出 YES/NO。
 * ###################################################################### */

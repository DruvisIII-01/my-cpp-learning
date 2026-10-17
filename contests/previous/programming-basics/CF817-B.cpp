#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string s1, s2 ; cin >> s1 >> s2 ;
    bool ans = true ;
    for(int t = 0 ; t < n ; ++t){
        char c1 = s1[t], c2 = s2[t] ;
        if(((c1 == 'G' || c1 == 'B') && c2 == 'R')||
        ((c2 == 'G' || c2 == 'B') && c1 == 'R')){
            ans = false ;
            break ;
        }
    }if(ans) cout << "YES" ;
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
 * 【题面与关键思路】Colourblindness
 * 题目链接：https://codeforces.com/problemset/problem/1722/B
 * 标签：难度 800 | implementation
 *
 * 关键思路：把 G 和 B 视为同一种颜色（RGB 的软区分），逐位比较两行：若同一位置一个是 R、另一个是 G/B 则 No；注意是"任一方向"的 R↔(G/B) 冲突。
 * ###################################################################### */

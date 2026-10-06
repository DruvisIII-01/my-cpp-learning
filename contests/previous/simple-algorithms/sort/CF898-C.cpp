#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int ans = 0 ; 
    for(int i = 1 ; i <= 10 ; ++i){
        for(int j = 1 ; j <= 10 ; ++j){
            char ch ; cin >> ch ; 
            if(ch == 'X'){
                for(int pt = 1 ; pt <= 5 ; ++pt){
                    if(pt == min(i, j) || 11 - pt == max(i, j)){
                        ans += pt ; 
                        break ;
                    }
                }
            }
        }
    }cout << ans ;
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
 * 【题面与关键思路】Target Practice
 * 题目链接：https://codeforces.com/problemset/problem/1873/C
 * 标签：难度 800 | implementation, math
 *
 * 关键思路：10×10 靶盘按格到边界的层数计分（外层 1 分…中心 5 分），逐格累加 X 的得分。
 * ###################################################################### */

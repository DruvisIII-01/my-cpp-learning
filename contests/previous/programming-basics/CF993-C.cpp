#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int m, a, b, c ; cin >> m >> a >> b >> c ;
    int ans = 0 ;
    if(m <= a) ans += m ;
    else{
        if(a + c >= m){
            c -= (m - a) ;
            ans += m ;
        }else{
            ans += (a + c) ;
            c = 0 ;
        }
    }
    // cout << a << ' ' << b << ' ' << c << ' ' ;
    // cout << ans << endl ;
    if(m <= b) ans += m ;
    else{
        if(b + c >= m){
            c -= (m - b) ;
            ans += m ;
        }else{
            //cout << "ooo" ;
            ans += (b + c) ;
            c = 0 ;
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
 * 【题面与关键思路】Hard Problem
 * 题目链接：https://codeforces.com/problemset/problem/2044/C
 * 标签：难度 800 | greedy, math
 *
 * 关键思路：两排座位各 m 个，a 人只坐第一排、b 人只坐第二排、c 人随意。贪心：每排先用专属的人填满，不够再用通用的 c 补；答案是两排各自 min(m, 可用人数) 之和。
 * ###################################################################### */

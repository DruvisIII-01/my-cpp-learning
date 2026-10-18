#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ; s = '*' + s ;
    vector<int> to_add ;
    int init = 0 ;
    for(int t = 1 ; t + t <= n + 1 ; t++){
        if(t + t == n + 1) {
            init += n - t ;
            continue ;
        }
        //left side look left or right side look right
        if(s[t] ==  'L') {
            to_add.push_back(n - 2 * t + 1) ;
            init += t - 1 ; 
        }else init += n - t ;
        if(s[n + 1 - t] == 'R') {
            to_add.push_back(n - 2 * t + 1) ;
            init += t - 1 ;
        }else init += n - t ;
    }
    for(int x : to_add) {
        init += x ;
        cout << init << ' ' ;
    }
    for(int t = to_add.size() + 1 ; t <= n ; ++t) cout << init << ' ' ;
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
 * 【题面与关键思路】Line
 * 题目链接：https://codeforces.com/problemset/problem/1722/D
 * 标签：难度 1100 | greedy,sortings
 *
 * 关键思路：贪心 + 排序：把每个人"面向中间/背向中间"的收益算出来，初始按"都朝向远的一侧"计分，再把所有"转身能变好"的收益排序后从大到小依次累加，每一步输出当前总分。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    map<string, int> mp ; 
    int n ; cin >> n ; 
    vector<vector<string>> strs(3, vector<string>(n)) ;
    for(int t = 0 ; t < 3 ; ++t){
        for(int i = 0 ; i < n ; ++i) {
            cin >> strs[t][i] ;
            mp[strs[t][i]]++ ; 
        }
    }
    vector<int> ans(3) ;
    for(int t = 0 ; t < 3 ; ++t){
        for(int i = 0 ; i < n ; ++i) {
            if(mp[strs[t][i]] == 1) ans[t] += 3 ;
            else if(mp[strs[t][i]] == 2) ans[t] += 1 ; 
        }
    }
    for(int t = 0 ; t < 3 ; ++t) cout << ans[t] << ' ' ;
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
 * 【题面与关键思路】Word Game
 * 题目链接：https://codeforces.com/problemset/problem/1722/C
 * 标签：难度 800 | data structures, implementation
 *
 * 关键思路：三个人各写 n 个单词，用 map 统计每个单词被几个人写过：只 1 人写过得 3 分，2 人得 1 分，3 人得 0 分，分别累加输出。
 * ###################################################################### */

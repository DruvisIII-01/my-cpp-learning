#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector<string> strs(n + 1) ;
    map<string, bool> mp ; 
    for(int t = 1 ; t <= n ; ++t){
        cin >> strs[t] ;
        mp[strs[t]] = true ;
    }for(int t = 1 ; t <= n ; ++t){
        int sz = strs[t].size() ; 
        int ans = 0 ;
        for(int i = 0 ; i < sz - 1 ; ++i){
            string str1 = strs[t].substr(0, i + 1) ;
            string str2 = strs[t].substr(i + 1) ;
            if(mp[str1] && mp[str2]) {
                ans = 1 ;
                break ;
            }
        }cout << ans ;
    }
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
 * 【题面与关键思路】Double Strings
 * 题目链接：https://codeforces.com/problemset/problem/1703/D
 * 标签：难度 1100 | brute force,data structures,strings
 *
 * 关键思路：用 map 存所有串，枚举每个串的拆分点，判断两半是否都在集合中；字符串哈希/哈希表查询。
 * ###################################################################### */

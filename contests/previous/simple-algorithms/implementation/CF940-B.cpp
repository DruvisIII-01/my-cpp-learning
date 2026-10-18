#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;
    string r = "" ;
    vector <bool> hsh(26) ;
    vector <int> idx(26) ;
    for(char ch : s) hsh[ch - 'a'] = true ;
    for(int i = 0 ; i < 26 ; i++) if(hsh[i]) r = r + (char) ('a' + i) ;
    int sz = (int) r.size() ;
    for(int i = 0 ; i < sz ; i++) idx[r[i] - 'a'] = i ;
    for(char ch : s) cout << r[sz - 1 - idx[ch - 'a']] ;
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
 * 【题面与关键思路】A BIT of a Construction
 * 题目链接：https://codeforces.com/problemset/problem/1957/B
 * 标签：难度 1100 | bitmasks,constructive algorithms,greedy,implementation
 *
 * 关键思路：把字符串中出现过的字符去重排序得到 r，再建立 r[i] <-> r[len-1-i] 的镜像映射，替换每个字符输出。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    int cnt[26][26] ;
    for(int i = 0 ; i < 26 ; i++){
        for(int j = 0 ; j < 26 ; j++){
            cnt[i][j] = 0 ;
        }
    }
    vector <string> ss(n + 1) ;
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++){
        cin >> ss[i] ;
        for(int j = 0 ; j < 26 ; j++){
            if(j + 'a' == ss[i][0]) continue ;
            ans += cnt[j][ss[i][1] - 'a'] ;
        }
        for(int j = 0 ; j < 26 ; j++){
            if(j + 'a' == ss[i][1]) continue ;
            ans += cnt[ss[i][0] - 'a'][j] ;
        }
        cnt[ss[i][0] - 'a'][ss[i][1] - 'a']++ ;
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
 * 【题面与关键思路】2-Letter Strings
 * 题目链接：https://codeforces.com/problemset/problem/1669/E
 * 标签：难度 1200 | data structures,math,strings
 *
 * 关键思路：用 26×26 桶统计每对 (c1,c2) 的串数；答案 = Σ (同首字母的串数 − 1) + (同末字母的串数 − 1)。
 *
 * 题号备注：本题属于 **Codeforces Round 784 (Div. 4)，contestId 1669**（2022-04-21）。
 *    早期文件名写成 CF786 是笔误（官方 Round 786 是 Div.3，题目完全不同），现已改名为 CF784。
 * ###################################################################### */

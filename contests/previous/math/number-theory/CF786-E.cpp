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
 * 标签：难度 1200 | data structures, math, strings
 *
 * 关键思路：统计每对 (c1,c2) 的串数，答案 = Σ C(cnt[a][b],1)*(同首字母数-1) + (同末字母数-1)，用 26×26 桶 O(n)。
 * ###################################################################### */

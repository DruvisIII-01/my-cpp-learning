#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(2 * n + 1) ;
    vector <bool> vis(n + 1) ;
    for(int i = 1 ; i <= 2 * n ; i++){
        cin >> a[i] ;
        if(!vis[a[i]]){
            vis[a[i]] = true ;
            cout << a[i] << ' ' ;
        }
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
 * 【题面与关键思路】Restore the Permutation by Merger
 * 题目链接：https://codeforces.com/problemset/problem/1385/B
 * 标签：难度 800 | greedy
 *
 * 关键思路：要让序列变"好"（先增后减的单峰），等价于保留一个后缀；从右往左找最长合法后缀，答案 = 前缀长度。
 * ###################################################################### */

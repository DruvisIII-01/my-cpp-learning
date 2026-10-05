#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    vector <int> a(n + 1) ;
    vector <int> b(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    for(int i = 1 ; i <= n ; i++) cin >> b[i] ;
    bool ans = true ;
    for(int i = 1 ; i <= n - k ; i++){
        if(b[i] == -1) continue ;
        if(b[i] != a[i]) {
            ans = false ;
            break ;
        }
    }
    if(!ans){
        cout << "NO" ;
        return ;
    }
    for(int i = k + 1 ; i <= n ; i++){
        if(b[i] == -1) continue ;
        if(b[i] != a[i]) {
            ans = false ;
            break ;
        }
    }
    if(!ans){
        cout << "NO" ;
        return ;
    }
    set <int> check ;
    for(int i = n + 1 - k ; i <= k ; i++) check.insert(a[i]) ;
    for(int i = n + 1 - k ; i <= k ; i++) {
        if(b[i] == -1) continue ;
        int cnt = check.count(b[i]) ;
        if(cnt == 0) {
            ans = false ;
            break ;
        }
        else if(cnt == 1) check.erase(b[i]) ;
    }
    if(!ans) {
        cout << "NO" ;
        return ;
    }cout << "YES" ;
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
 * 【题面与关键思路】Equal Multisets (Easy Version)
 * 题目链接：https://codeforces.com/problemset/problem/2211/C1
 * 标签：难度 1300 | binary search, brute force, greedy, two pointers
 *
 * 关键思路：把 a、b 排序后双指针配对，判断能否通过整体加减同一常数变成同一个多重集；只需输出 YES/NO。
 * ###################################################################### */

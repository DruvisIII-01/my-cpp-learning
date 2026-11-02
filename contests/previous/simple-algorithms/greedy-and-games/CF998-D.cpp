#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ; 
    vector<int> b(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        b[t] = a[t] ;
    }

    for(int t = 1 ; t < n ; ++t) {
        if(b[t] <= b[t + 1]){
            b[t + 1] = b[t + 1] - b[t] ;  
            b[t] = 0 ;
        }else{
            cout << "NO" ;
            return ;
        }
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

/* ##################################################################
 * 【题面与关键思路】Subtract Min Sort
 * 题目链接：https://codeforces.com/problemset/problem/2060/D
 * 标签：难度 1100 | greedy
 *
 * 关键思路：从左往右：若 a[i] ≤ a[i+1]，就令 a[i+1] −= a[i]（相当于允许把后者减到不小于前者），继续；一旦出现 a[i] > a[i+1] 就无法满足，输出 NO。
 * ################################################################## */

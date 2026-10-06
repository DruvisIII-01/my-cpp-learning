#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
    
    vector<int> b(n + 1) ;
    vector<string> stp(n + 1) ;
    for(int t = 1 ; t <= n ; ++t){
        cin >> b[t] >> stp[t] ;
        int add = 0 ;
        for(char ch : stp[t]){
            if(ch == 'D') add++ ;
            else if(ch == 'U') add-- ;
        }cout << (a[t] + add + 100000) % 10 << ' ' ;
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
 * 【题面与关键思路】Cypher
 * 题目链接：https://codeforces.com/problemset/problem/1703/C
 * 标签：难度 800 | brute force, implementation, strings
 *
 * 关键思路：按 U/D 指令把每位数字在 0..9 上循环移动，最后输出锁的状态。
 * ###################################################################### */

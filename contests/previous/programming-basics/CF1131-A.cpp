#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ; 
    string p, q ; cin >> p >> q ;
    vector<int> hsh(26) ;

    for(char ch : p) hsh[ch - 'a']++ ;
    for(char ch : q) hsh[ch - 'a']-- ;
    
    bool ans = true ; 
    for(int t = 'a' ; t <= 'z' ; ++t){
        int idx = t - 'a' ;
        if(t == 's' || t == 'x' || t == 'i'){
            if(hsh[idx] != 1) {
                ans = false ;
                break ;
            }
        }else if(hsh[idx] != 0){
            ans = false ;
            break ;
        }
    }if(ans) cout << "YES" ;
    else cout << "NO" ;
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
 * 【题面与关键思路】Fraction and Six
 * 题目链接：https://codeforces.com/problemset/problem/2278/A
 * 标签：难度 2278A（新场次，暂无 rating） | implementation, sortings, strings
 *
 * 关键思路：两把"锁"的字符多重集必须只差 s、x、i 各一个：用 26 位计数数组做差，要求 s/x/i 的净差恰为 1、其余字母净差为 0。
 * ################################################################## */

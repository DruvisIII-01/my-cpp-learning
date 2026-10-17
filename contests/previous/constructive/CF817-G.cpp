#include <bits/stdc++.h>
using namespace std ;

#define int long long
int calc(int x){
    int res = 1 ;
    for(int t = 1 ; t <= 32 ; ++t){
        res = res << 1 ;
        if(res > x) return res ;
    }return -1 ;  
}

void solve(){
    int n ; cin >> n ; 
    if(n == 3){
        cout << "1 3 2" ;
        return ; 
    }
    
    int k = n / 2 ;
    vector<int> odd ; vector<int> even ;
    int all_xor1 = calc(n), all_xor2 = 0 ;
    odd.push_back(calc(n)) ;
    for(int t = 1 ; t < k ; ++t) {
        odd.push_back(t) ;
        even.push_back(t + k) ;
        all_xor1 ^= t ;
        all_xor2 ^= t + k ;
    }even.push_back(all_xor1 ^ all_xor2) ;

    for(int t = 0 ; t < odd.size() ; ++t)
    cout << odd[t] << ' ' << even[t] << ' ' ;
    if(n % 2) cout << 0 ;
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
 * 【题面与关键思路】Even-Odd XOR
 * 题目链接：https://codeforces.com/problemset/problem/1722/G
 * 标签：难度 1500 | bitmasks, constructive algorithms, greedy
 *
 * 关键思路：构造 n 个数使异或和为 0 且奇偶位置各自异或相等。先取一个 ≥ n 的 2 的幂，把奇数位放 "1..k" + 该幂，偶数位放 "k+1..2k"，最后一位用"前面异或的修正值"补齐；n 为奇数时补一个 0。
 * ###################################################################### */

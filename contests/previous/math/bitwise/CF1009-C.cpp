#include <bits/stdc++.h>
using namespace std ;

int n ; 

bool judge (int x){
    if(x <= 1) return false ;
    if((x & (x - 1)) == 0) return false ;
    if(((x + 1) & x) == 0) return false ; 
    return true ;
}

int calc(int x){
    int res = 1 ;
    while(res & x){
        res <<= 1 ;
    }return res ;
}

void solve(){
    cin >> n ; 
    if(!judge(n)) {cout << "-1" ; return ; }

    int s = (int)(log2(1.0 * n)) ;
    int ans = calc(n) ;
    cout << n - (1 << s) + ans ; 
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
 * 【题面与关键思路】XOR and Triangle
 * 题目链接：https://codeforces.com/problemset/problem/2074/C
 * 标签：难度 1100 | bitmasks,brute force,geometry,greedy,probabilities
 *
 * 关键思路：判定 x 能否作为三角形第三边：x 既不能是 2 的幂（否则退化），也不能是 2^k - 1（否则两边相等），满足则 YES。
 * ###################################################################### */

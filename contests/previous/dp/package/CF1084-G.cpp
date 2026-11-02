#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 1000000007 ;
const int MAXN = 3033 ; 
int C[MAXN][MAXN] ;

int q_pow(int a, int x){
    int res = 1, mul = a ; 
    while(x){
        if(x & 1) res *= mul ; res %= mod ;
        mul = mul * mul ; mul %= mod ;
        x >>= 1 ;
    }return res ;
}int inv(int x) {return q_pow(x, mod - 2) ;}

void solve(){
    int n, x ; cin >> n >> x ;
    vector<int> a, b ;string op ;
    for(int t = 1 ; t <= n ; ++t){
        cin >> op ;
        char sgn = op[0] ;
        int num = stoll(op.substr(1)) ;
        if(sgn == '+') b.push_back(num) ;
        else if(sgn == '-') b.push_back((mod - num) % mod) ;
        else if(sgn == 'x') a.push_back(num % mod) ;
        else if(sgn == '/') a.push_back(inv(num)) ;
        //cout << num << endl ;
    }//for(int x : b) cout << x << ' ' ; 

    int all_mul = 1, all_sum = 0 ;
    int sz_a = a.size(), sz_b = b.size() ;
    for(int t = 0 ; t < sz_a ; ++t)
    all_mul = (a[t] * all_mul + mod) % mod ;
    for(int t = 0 ; t < sz_b ; ++t)
    all_sum = (b[t] + all_sum + mod) % mod ;

    vector<int> e(sz_a + 1) ; e[0] = 1 ;
    for(int t = 0 ; t < sz_a ; ++t) {
        for(int r = t + 1 ; r >= 1 ; r--)
        e[r] = (e[r] + e[r - 1] * a[t] + mod) % mod ;
    }int sum_e = 0 ;
    for(int t = 0 ; t <= sz_a ; ++t)
    sum_e = (sum_e + e[t] * inv(C[sz_a][t]) + mod) % mod ;
    sum_e = (sum_e * inv(sz_a + 1) + mod) % mod ;

    int Exp_a = all_mul, Exp_b = all_sum * sum_e ;
    cout << (Exp_a * x + Exp_b + mod) % mod ; 

}

signed main() {
    int T ;cin >> T ;
    for(int i = 0 ; i < MAXN ; ++i){
        for(int j = 0 ; j <= i ; ++j){
            if(j == 0) C[i][j] = 1 ;
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j] + mod) % mod ;
        }
    }
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】Operation Permutation
 * 题目链接：https://codeforces.com/problemset/problem/2200/G
 * 标签：难度 2200 | combinatorics, dp, math, probabilities
 *
 * 关键思路：读入形如 +x/−x 的操作，统计正负数量并用组合数 C(n,k) 分配；预处理阶乘/逆元，按"总步数"累加方案数。
 * ################################################################## */

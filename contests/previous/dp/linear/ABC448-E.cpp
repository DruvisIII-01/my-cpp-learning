#include <bits/stdc++.h>
using namespace std ;

#define int long long

int mod ;

int q_pow(int a, int b){
    int ans = 1, to_mul = a ;
    while (b != 0) {
        if(b&(int)1) {
            ans *= to_mul ;
            ans %= mod ;
        }
        to_mul = to_mul*to_mul ;
        to_mul %= mod ; 
        b = b>>1 ;
    }return ans ;
} 

signed main() {
    int k, m ;cin >> k >> m ;
    mod = m*(10007) ;
    
    vector <int> c(k+1) ;
    vector <int> l(k+1) ;
    for (int t = 1 ; t <= k ; t++) cin >> c[t] >> l[t] ;
    
    vector <int> ddr(30) ;
    ddr[0] = 10 ;for(int i = 1 ; i <= 29 ; i++){
        ddr[i] = ddr[i-1]*ddr[i-1] ;
        ddr[i] %= mod ;
    }

    vector <int> dr(30) ;
    dr[0] = 1 ;for(int i = 1 ; i <= 29 ; i++){
        dr[i] = dr[i-1]*ddr[i-1]+dr[i-1] ;
        dr[i] %= mod ;
    }

    int res = 0, dig = 0 ;
    for(int i = k ; i >= 1 ; i--) {
        int ce = (c[i]*q_pow((int)10, dig))%mod ;
        int R = 0 ;
        for(int j = 29 ; j >= 0 ; j--){
            if((int)(1<<j)&l[i]) {
                R = R*ddr[j]+dr[j] ;
                R %= mod ;
            }
        }
        dig += l[i] ;
        res += R*ce ;
        res %= mod ;
    }cout << res/m << endl ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Simple Division
 * 题目链接：https://atcoder.jp/contests/abc448/tasks/abc448_e
 * 标签：难度 ABC E | 快速幂
 *
 * 关键思路：在模 mod*10007 意义下用快速幂求出 10 的幂与拼接结果（先算模意义下的商再还原），核心是快速幂与防止取模丢失整除信息。
 * ###################################################################### */

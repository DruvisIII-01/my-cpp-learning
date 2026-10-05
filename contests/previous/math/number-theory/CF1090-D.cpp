#include <bits/stdc++.h>
using namespace std ;

#define int long long

map <int, int> prime ;

bool is_prime(int x){
    if(x == 1) return false ;
    if(x == 2) return true ;
    if(x % 2 == 0) return false ;
    for(int i = 3 ; i*i <= x ; i++){
        if(x % i == 0) return false ;
    }return true ;
} 

void construct(){
    prime[0] = 1 ;
    int index = 1 ;
    int num = 2 ;
    while(index <= 1e4 + 5){
        if(is_prime(num)){
            prime[index] = num ;
            index++ ;
        }
        num++ ;
    }
}

void solve(){
    int n ; cin >> n ;
    for(int i = 1 ; i <= n ; i++){
        cout << prime[i - 1] * prime[i] << ' ' ;
    }
}

signed main() {
    int T ;cin >> T ;
    construct() ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】The 67th OEIS Problem
 * 题目链接：https://codeforces.com/problemset/problem/2218/D
 * 标签：难度 1100 | constructive algorithms, greedy, math, number theory
 *
 * 关键思路：取前 n 个素数 p1..pn，令 a[i] = p[i]*p[i+1]，则相邻不互质、不相邻互质，用素数筛 + 构造。
 * ###################################################################### */

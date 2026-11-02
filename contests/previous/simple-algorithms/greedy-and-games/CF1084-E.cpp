#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXV = 1111111 ;
int spf[MAXV] ;
bool only[MAXV] ;

bool only_one(int x){
    if(x == 1) return true ; 
    int only = spf[x] ;
    while(x % only == 0){
        x /= only ;
    }return (x == 1) ;
}

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    //special judge
    bool Bob0 = true ;
    for(int t = 2 ; t <= n ; ++t) {
        if(a[t] < a[t - 1]){
            Bob0 = false ;
            break ;
        }
    }if(Bob0) {
        cout << "Bob" ;
        return ;
    }

    bool Alice0 = false ;
    for(int t = 1 ; t <= n ; ++t){
        if(!only[a[t]]){
            Alice0 = true ;
            break ;
        }
    }if(Alice0){
        cout << "Alice" ;
        return ;
    }

    vector<int> s(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) {
        if(a[t] == 1) s[t] = 1 ;
        else s[t] = spf[a[t]] ;
    }
    bool Bob1 = true ;
    for(int t = 2 ; t <= n ; ++t){
        if(s[t] < s[t - 1]){
            Bob1 = false ;
            break ;
        }
    }if(Bob1) cout << "Bob" ;
    else cout << "Alice" ;
}

signed main() {
    for(int t = 2 ; t < MAXV ; ++t){
        if(!spf[t]){
            spf[t] = t ;
            for(int i = t * t ; i < MAXV ; i += t){
                if(!spf[i]) spf[i] = t ;
            }
        }
    }
    for(int t = 1 ; t < MAXV ; ++t) only[t] = only_one(t) ;
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】Divisive Battle
 * 题目链接：https://codeforces.com/problemset/problem/2200/E
 * 标签：难度 1500 | games, greedy, math, number theory
 *
 * 关键思路：用最小质因子筛（spf）把每个数化成"是否只有一个质因子"；先判初始数组是否合法（Bob 直接赢），再按质因子种类数与奇偶做博弈判定。
 * ################################################################## */

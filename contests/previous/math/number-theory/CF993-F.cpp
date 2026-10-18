#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n, m, q ; cin >> n >> m >> q ;
    vector<int> a(n + 1) ; vector<int> b(m + 1) ;
    unordered_map<int, bool> visA ; unordered_map<int, bool> visB ;
    int sumA = 0 ; int sumB = 0 ; 
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        visA[n + a[t]] = true ;
        sumA += a[t] ;
    }
    sort(a.begin() + 1, a.end()) ;
    for(int t = 1 ; t <= m ; ++t) {
        cin >> b[t] ;
        visB[m + b[t]] = true ;
        sumB += b[t] ;
    }
    for(int t = 1 ; t <= q ; ++t){
        int x ; cin >> x ;
        vector<int> pos ;
        if(!x) pos.push_back(0) ;
        else for(int i = 1 ; i * i <= abs(x) ; ++i) if(x % i == 0) pos.push_back(i) ;     
        bool is_ok = false ;
        for(int i : pos){
            if(i){
                if(visA[sumA - i + n] && visB[sumB - x / i + m]) is_ok = true ;
                if(visA[sumA + i + n] && visB[sumB + x / i + m]) is_ok = true ;
                if(visA[sumA - x / i + n] && visB[sumB - i + m]) is_ok = true ;
                if(visA[sumA + x / i + n] && visB[sumB + i + m]) is_ok = true ;
            }if(is_ok) break ;
        }if(is_ok) cout << "YES" << endl ;
        else cout << "NO" << endl ;
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Easy Demon Problem
 * 题目链接：https://codeforces.com/problemset/problem/2044/F
 * 标签：难度 1900 | binary search,brute force,data structures,math,number theory
 *
 * 关键思路：问能否通过交换 a 中一个数 x 与 b 中一个数 y 使两个数组元素和相等 —— 等价于 (sumA − x) − (sumB − y) = 0，即 x − y = sumA − sumB = X。把 a、b 的值存进哈希表，枚举 |X| 的约数 d 与 X/d 作为 (x, y) 的候选（四种符号组合）查询是否同时存在。
 * ###################################################################### */

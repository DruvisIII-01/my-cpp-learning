#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n ; cin >> n ;
    vector <int> x(n), y(n) ;
    for(int i = 0 ; i < n ; i++) cin >> x[i] >> y[i] ;
    
    int B = 2e7 / sqrt(n) ;

    vector <int> ord(n) ;
    for(int i = 0 ; i < n ; i++) ord[i] = i ;
    sort(ord.begin(), ord.end(), 
    [&](int i, int j){
        if(x[i] / B != x[j] / B) return x[i] < x[j] ;
        if((x[i] / B) % 2) return y[i] > y[j] ;
        return y[i] < y[j] ; 
    }) ;

    int start = 0 ;
    while(ord[start] != 0) start++ ;
    rotate(begin(ord), begin(ord) + start, end(ord)) ;
    for(int i = 0 ; i < n ; i++) cout << ord[i] + 1 << " \n"[i + 1 == n] ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Authentic Traveling Salesman Problem
 * 题目链接：https://atcoder.jp/contests/abc448/tasks/abc448_f
 * 标签：难度 ABC F | 构造
 *
 * 关键思路：把点按 x 分块排序、块内按 y 交替方向输出，使曼哈顿路径长度不超过给定上界；分块阈值取 2e7/sqrt(n) 量级。
 * ###################################################################### */

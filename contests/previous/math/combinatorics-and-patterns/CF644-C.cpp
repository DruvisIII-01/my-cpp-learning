#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    vector <int> odds ;
    vector <int> evens ;
    int odd = 0, even = 0 ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        if(a[i] % 2){
            odd++ ;
            odds.push_back(a[i]) ;
        }else{
            even++ ;
            evens.push_back(a[i]) ;
        }
    }if(odd % 2 == 0 && even % 2 == 0){
        cout << "YES" ;
        return ;
    }for(auto x : odds){
        for(auto y : evens){
            if(abs(x - y) == 1){
                cout << "YES" ;
                return ;
            }
        }
    }cout << "NO" ;
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
 * 【题面与关键思路】Similar Pairs
 * 题目链接：https://codeforces.com/problemset/problem/1360/C
 * 标签：难度 1100 | constructive algorithms,graph matchings,greedy,sortings
 *
 * 关键思路：统计奇偶数的个数：两者都是偶数则可行；否则需要一对差为 1 的奇偶元素交换配对（排序后检查相邻差 1）。
 * ###################################################################### */

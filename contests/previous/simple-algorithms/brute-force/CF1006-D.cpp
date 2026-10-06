#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    //special judge 
    bool increased = true ; 
    for(int i = 2 ; i <= n ; ++i){
        if(a[i] < a[i - 1]) { increased = false ; break ;}
    }if(increased) {cout << '1' << ' ' << '1' ; return ;}

    vector <vector <int>> ta(n + 1, vector<int>(n + 1, 0)) ;
    vector <vector <int>> tb(n + 1, vector<int>(n + 1, 0)) ;
    for(int i = 1 ; i <= n ; ++i){
        ta[i][i] = tb[i][i] = 0 ;
        for(int j = 1 + i ; j <= n ; ++j){
            ta[i][j] = ta[i][j - 1] + (a[j] > a[i]) ;
            tb[i][j] = tb[i][j - 1] + (a[j] < a[i]) ;
        }
    }
    
    int mx = -1 ; 
    int mx_l = -1, mx_r = -1 ;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            int cur = tb[i][j] - ta[i][j] ;
            if(cur > mx){
                mx = cur ; 
                mx_l = i ; 
                mx_r = j ; 
            }
        }
    }

    cout << mx_l << ' ' << mx_r ; 
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
 * 【题面与关键思路】For Wizards, the Exam Is Easy, but I Couldn't Handle It
 * 题目链接：https://codeforces.com/problemset/problem/2072/D
 * 标签：难度 1300 | brute force, greedy, implementation
 *
 * 关键思路：只能把一个区间内所有数减 1，要使数组变成"每对相邻差 <= 1"。O(n^2) 枚举区间，用计数表 O(1) 计算改动后的最大/最小相邻差，取最小操作次数。
 * ###################################################################### */

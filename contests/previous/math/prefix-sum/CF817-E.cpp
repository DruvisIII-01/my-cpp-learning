#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXW = 1111 ;
void Prt(vector<vector<int>>&a){
    for(int i = 1 ; i <= 5 ; ++i){
        for(int j = 1 ; j <= 5 ; ++j){
            cout << a[i][j] << ' ' ;
        }cout << endl ;
    }
}
void solve(){
    int n, q ; cin >> n >> q ;   
    vector<vector<int>> diff(MAXW, vector<int>(MAXW)) ; 
    for(int t = 1 ; t <= n ; ++t){
        int h, w ; cin >> h >> w ;
        if(h > 1 && w > 1){
            diff[1][w] -= h * w ;
            diff[h][1] -= h * w ;
            diff[h][w] += h * w ;
            diff[1][1] += h * w ;
        }
    }
    vector<vector<int>> ans(MAXW, vector<int>(MAXW)) ;
    for(int i = 1 ; i < MAXW ; ++i){
        for(int j = 1 ; j < MAXW ; ++j){
            ans[i][j] += (ans[i - 1][j] + ans[i][j - 1]
            -ans[i - 1][j - 1] + diff[i][j]) ;
        }
    }
    //cout << 'a' << endl ; 
    // Prt(ans) ;
    for(int t = 1 ; t <= q ; t++){
        int hs, ws, hb, wb ; cin >> hs >> ws >> hb >> wb ;
        // cout << ans[hs][ws] << ' ' << ans[hb - 1][wb - 1] << '\n' ;
        cout << ans[hs][ws] 
            - ans[hs][wb - 1] - ans[hb - 1][ws]
            + ans[hb - 1][wb - 1] << '\n' ;
    }
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        //cout << endl ;
    }
    return 0;
}
/* ######################################################################
 * 【题面与关键思路】Counting Rectangles
 * 题目链接：https://codeforces.com/problemset/problem/1722/E
 * 标签：难度 1600 | brute force,data structures,dp,implementation
 *
 * 关键思路：按题意把每个 h×w 矩形"贡献"到二维差分数组（四角加/减 h*w），再对差分做二维前缀和得到"面积前缀"；每次询问用二维前缀和的容斥 O(1) 求答案。核心技巧：二维差分 + 二维前缀和互为逆运算。
 *
 * 本题已归档到 math/difference：二维差分 + 二维前缀和。
 * ###################################################################### */

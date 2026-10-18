#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(const string& s, int l, int r, char c){
    if(l == r){
        if(c == s[l]) return 0 ; 
        else return 1 ;
    }
    int mid = (l + r) >> 1 ;
    int Lchange = 0;
    int Rchange = 0 ;
    for(int i = l ; i <= mid ; i++){
        if(s[i] != c) Lchange++ ;
    }int ans1 = Lchange + solve(s, mid + 1, r, c + 1) ;
    for(int i = mid + 1 ; i <= r ; i++){
        if(s[i] != c) Rchange++ ;
    }int ans2 = Rchange + solve(s, l, mid, c + 1) ;
    return min(ans1, ans2) ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        int n ; cin >> n ;
        string s ; cin >> s ;
        int ans = solve(s, 0, n - 1, 'a') ;
        cout << ans << endl ;
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】a-Good String
 * 题目链接：https://codeforces.com/problemset/problem/1385/D
 * 标签：难度 1500 | bitmasks,brute force,divide and conquer,dp,implementation
 *
 * 关键思路：定义 a-good 串：左半全为 c、右半为 (c+1)-good（或对称）。分治 solve(l,r,c)：把左半全改成 c 的代价 + 递归右半，与对称情况取 min，O(n log n)。
 * ###################################################################### */

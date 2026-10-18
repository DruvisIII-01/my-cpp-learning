#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;
        
        int ans = -1 ;
        if (n <= 3) {
            ans = 1 ;
        }
        else{
            int d = min(abs(x1 - x2), n - abs(x1 - x2)); 
            ans = d + k ;
        }
        cout << ans << endl ;
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Remilia Plays Soku
 * 题目链接：https://codeforces.com/problemset/problem/2228/B
 * 标签：难度 1100 | games,implementation
 *
 * 关键思路：环形位置上两点的最短距离 = min(|x1-x2|, n-|x1-x2|)，再与 k 做简单运算；注意 n 很小时的边界特判。
 * ###################################################################### */

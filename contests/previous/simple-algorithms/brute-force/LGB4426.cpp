#include <bits/stdc++.h>
using namespace std ;

//#define int long long

const int MAXN = 22452 ;
int dp[MAXN][2] ;
//consider to i-th element and swtich a[1] to j
//best action to modify array a takes dp[i][j] steps
signed main() {
    string s ;cin >> s ;
    int n = s.size() ;
    vector <int> a(n+1, 0) ;
    vector <int> pre(n+1, 0) ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == 'I') a[i+1] = 1 ;
        else a[i+1] = 0 ;
    }for(int i = 1 ; i <= n ; i++){
        pre[i] = pre[i-1]+a[i] ;
    }int mi = INT_MAX ;
    for(int left = 1 ; left <= n-2 ; left++){
        for(int right = left+2 ; right <= n ; right++){
            mi = min(mi, 
            left-2*pre[left]+2*pre[right-1]
            +n-right+1-pre[n]) ;
        }
    }cout << mi << endl ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】B4426 [CSP-X2025 山东] IOI 串
 * 题目链接：https://www.luogu.com.cn/problem/B4426
 * 标签：难度 洛谷 | 前缀和, 枚举分界点
 *
 * 关键思路：目标串形如 I…IO…OI…I，枚举两个分界点，用前缀和 O(1) 求出把三段分别改成目标字符的代价，取最小值，O(n^2)。
 * ###################################################################### */

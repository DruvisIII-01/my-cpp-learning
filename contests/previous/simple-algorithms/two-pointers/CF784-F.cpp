#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    vector <int> pre(n + 1) ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        pre[i] = pre[i - 1] + a[i] ;
    }
    // vector <int> suf(n + 1) ;
    // suf[n] = a[n] ;
    // for(int i = n - 1 ; i >= 1 ; i--){
    //     suf[i] = suf[i + 1] + a[i] ;
    // }
    int check = pre[n] / 2 ;
    int end = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(pre[i] > check) {
            end = i - 1 ;
            break ;
        }
    }
    int ans = 0 ;
    int left_sum = 0, right_sum = 0 ;
    int right = n ;
    for(int left = 1 ; left <= end ; left++){
        left_sum += a[left] ;
        while(right > left && left_sum > right_sum) {
            right_sum += a[right] ;
            right-- ;
        }
        //printf("%d %d %d %d\n", left, right, left_sum, right_sum) ;
        if(right_sum == left_sum) ans = n - right + left ; 
    }
    cout << ans ;
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
 * 【题面与关键思路】Eating Candies
 * 题目链接：https://codeforces.com/problemset/problem/1669/F
 * 标签：难度 1100 | binary search, data structures, greedy, two pointers
 *
 * 关键思路：求"左侧前缀和 == 右侧后缀和"的最大总颗数：左右双指针，哪边和小就往哪边扩。
 *
 * 题号备注：本题属于 **Codeforces Round 784 (Div. 4)，contestId 1669**（2022-04-21）。
 *    早期文件名写成 CF786 是笔误（官方 Round 786 是 Div.3，题目完全不同），现已改名为 CF784。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, q ; cin >> n >> q ;
    vector <int> a(n + 1) ;
    vector <int> pre(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    sort(a.begin() + 1, a.begin() + n + 1, greater<int>()) ;
    for(int i = 1 ; i <= n ; i++) pre[i] = pre[i - 1] + a[i] ;
    //for(int i = 1 ; i <= n ; i++) cout << pre[i] << ' ' ;
    cout << endl ;
    while(q--){
        int x ; cin >> x ;
        if(pre[n] < x) {
            cout << '-' << '1' << endl ;
            continue ;
        }
        int left = 0, right = n + 1 ;
        while(right != left + 1) {
            int mid = (left + right ) >> 1 ;
            if(pre[mid] >= x) right = mid ;
            else left = mid ;
        }
        cout << right << endl ;
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
 * 【题面与关键思路】Eating Queries
 * 题目链接：https://codeforces.com/problemset/problem/1676/E
 * 标签：难度 1100 | binary search,greedy,sortings
 *
 * 关键思路：降序排序求前缀和（单调），每个询问二分最小的 x 使前缀和 >= 询问值。
 *
 * 本题已归档到 math/prefix-sum：排序后前缀和单调，再用二分查找。
 * ###################################################################### */

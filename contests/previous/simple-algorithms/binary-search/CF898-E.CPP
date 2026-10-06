#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, x ; cin >> n >> x ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    sort(a.begin() + 1, a.begin() + n + 1) ;

    vector<int> sum(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) sum[t] = sum[t - 1] + a[t] ;
    // int mx = -1 ;
    // for(int t = 1 ; t <= n ; ++t) mx = max(a[t], mx) ;

    int left = -1, right = n + 1 ;
    while(left + 1 != right){
        int mid = (left + right) / 2 ;
        int water = a[mid] * mid - sum[mid] ;
        if(water >= x) right = mid ;
        else left = mid ;
    }

    // cout << right << ' ' ;
    int rest = x - ((right - 1) * a[right - 1] - sum[right - 1]) ;
    // cout << rest << ' ' ;
    cout << a[right - 1] + rest / (right - 1) ;
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
 * 【题面与关键思路】Building an Aquarium
 * 题目链接：https://codeforces.com/problemset/problem/1873/E
 * 标签：难度 1100 | binary search, sortings
 *
 * 关键思路：二分最终水位 h，用水量 = Σmax(0, h-a[i]) 随 h 单调，O(n log V)。
 * ###################################################################### */

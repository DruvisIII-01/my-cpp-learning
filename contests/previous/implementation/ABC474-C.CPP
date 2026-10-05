#include <bits/stdc++.h>
using namespace std ;

//#define int long long
int last[224524] ;
signed main() {
    int n, q ; cin >> n >> q ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    for(int t = 1 ; t <= q ; ++t) {
        int aq = -1 ; cin >> aq ;
        last[aq] = t ;
    }

    vector<int> ans ;
    vector<int> to_sort ;
    for(int t = 1 ; t <= n ; ++t) {
        if(!last[a[t]]) ans.push_back(a[t]) ;
        else to_sort.push_back(a[t]) ;
    }
    auto cmp = [](const int &i, const int &j){
        return last[i] < last[j] ;
    } ;
    sort(to_sort.begin(), to_sort.end(), cmp) ;
    for(int x : to_sort) ans.push_back(x) ;
    for(int x : ans) cout << x << ' ' ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Remove and Append
 * 题目链接：https://atcoder.jp/contests/abc474/tasks/abc474_c
 * 标签：难度 ABC C
 *
 * 关键思路：只关心每个数"最后一次被操作的时间"：没有出现过的保持原序，出现过的按最后操作时间排序输出（模拟 + 排序）。
 * ###################################################################### */

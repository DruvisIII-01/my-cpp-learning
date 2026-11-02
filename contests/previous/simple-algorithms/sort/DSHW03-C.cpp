#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int k ; cin >> k ;
    int t ; vector<int> a ;  
    while(cin >> t) a.push_back(t) ;
    sort(a.begin(), a.end(), greater<int>()) ;
    cout << a[k - 1] ;
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】DSHW03-C 第 k 大数
 * 来源：学院课程作业（非竞赛题，无官方难度/标签）
 * 标签：难度 课程作业 | 排序
 *
 * 关键思路：读入 k 和若干数，降序排序后取第 k 个。
 * ################################################################## */

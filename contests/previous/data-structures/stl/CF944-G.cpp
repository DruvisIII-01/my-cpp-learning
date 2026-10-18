#include <bits/stdc++.h>
using namespace std ;

#define int long long

int n ; 

void solve(){
    cin >> n ;
    vector <int> a(n + 123) ;
    map <int, priority_queue<int, vector<int>, greater<int>>> mp ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    for(int i = 1 ; i <= n ; i++) {
        int mk = a[i] >> 2 ;
        mp[mk].push(a[i]) ;
    }
    for(int i = 1 ; i <= n ; i++) {
        int mk = a[i] >> 2 ;
        int tmp = mp[mk].top() ;
        cout << tmp << ' ' ;
        mp[mk].pop() ;
    } 
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
 * 【题面与关键思路】XOUR
 * 题目链接：https://codeforces.com/problemset/problem/1971/G
 * 标签：难度 1700 | data structures,dsu,sortings
 *
 * 关键思路：同一组元素（a>>2 相同）内部可任意交换，组内排序后按原位置填回最小值即字典序最小；用 map<int, priority_queue>（小根堆）维护每组。
 * ###################################################################### */

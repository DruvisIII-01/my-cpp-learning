#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 514514 ;
int tree[MAXN << 2] ;

void add_tree(int x, int l, int r, int i){
    if(x == l && x == r){
        tree[i]++ ;
        return ;
    }if(x < l || r < x) return ;
    int mid = (l + r) / 2 ;
    add_tree(x, l, mid, i * 2) ;
    add_tree(x, mid + 1, r, i * 2 + 1) ;
    tree[i] = tree[i * 2] + tree[i * 2 + 1] ;
}

int query_tree(int jobl, int jobr, int l, int r, int i){
    if(jobl <= l && jobr >= r) return tree[i] ;
    if(jobr < l || jobl > r) return 0 ;
    int mid = (l + r) / 2 ;
    return query_tree(jobl, jobr, l, mid, i * 2) + 
    query_tree(jobl, jobr, mid + 1, r, i * 2 + 1) ;
}

signed main() {
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ; 

    int ans = 0 ;
    for(int t = 1 ; t <= n ; ++t) {
        //cout << t << endl ; 
        int x = a[t] ;
        ans += query_tree(1, n, 1, n, 1) - query_tree(1, x, 1, n, 1) ;
        //cout << query_tree(1, n, 1, n, 1) << ' ' << query_tree(1, x, 1, n, 1) << endl ;
        add_tree(x, 1, n, 1) ;
        
    }cout << ans ;
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】DSHW04-A 线段树求逆序对
 * 来源：数据结构课程作业（非竞赛题，无官方难度/标签）
 * 标签：课程作业 | 线段树（点更新 + 区间查询）
 *
 * 关键思路：把值域建成线段树：从左到右逐个插入 a[i]（点 +1），再查询比 a[i] 大的已插入个数并累加，即逆序对数。
 * ################################################################## */

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
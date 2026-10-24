#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 114514 ;
const long long inf = 2147483647 ;
int a[MAXN] ;
int tree[MAXN << 2] ;
int to_min[MAXN << 2] ;
bool flag[MAXN << 2] ;
 
void build_tree(int l, int r, int i){
    if(l == r){
        tree[i] = a[l] ;
        return ; 
    }int mid = (l + r) >> 1 ;
    build_tree(l, mid, i << 1) ;
    build_tree(mid + 1, r, i << 1 | 1) ;
    tree[i] = min(tree[i << 1], tree[i << 1 | 1]) ;
}

void lazy(int i, int k){
    tree[i] = k ;
    to_min[i] = k ;
    flag[i] = true ;
}

void down(int i){
    if(flag[i]){
        lazy(i << 1, to_min[i]) ;
        lazy(i << 1 | 1, to_min[i]) ;
        to_min[i] = inf ;
        flag[i] = false ;
    }
}

int query_tree(int l, int r, int i, int jobl, int jobr){
    if(l >= jobl && r <= jobr) return tree[i] ;
    else if(l > jobr || r < jobl) return inf ;
    down(i) ;
    int mid = (l + r) >> 1 ;
    return min(query_tree(l, mid, i << 1, jobl, jobr),
    query_tree(mid + 1, r, i << 1| 1, jobl, jobr) ) ;
}

void update_tree(int l, int r, int i, int jobl, int jobr, int k){
    if(l >= jobl && r <= jobr) {
        lazy(i, k) ;
        return ;
    }else if(l > jobr || r < jobl) return ;
    down(i) ;
    int mid = (l + r) >> 1 ;
    update_tree(l, mid, i << 1, jobl, jobr, k) ;
    update_tree(mid + 1, r, i << 1 | 1, jobl, jobr, k) ;
    tree[i] = min(tree[i << 1], tree[i << 1 | 1]) ;
}

signed main() {
    int n, q ; cin >> n >> q ;
    for(int t = 0 ; t < MAXN ; ++t) a[t] = inf ;
    for(int t = 0 ; t < (MAXN << 2) ; ++t) to_min[t] = inf ;
    for(int t = 0 ; t < (MAXN << 2) ; ++t) flag[t] = 0 ;
    
    build_tree(0, n - 1, 1) ;
    // for(int t = 1 ; t <= 4 * (n - 1) ; ++t) cout << tree[t] << endl ;cout << "=============================" << endl ;
    for(int T = 1 ; T <= q ; ++T){
        int op, x, y ; cin >> op >> x >> y ;
        if(!op) update_tree(0, n - 1, 1, x, x, y) ;
        else cout << query_tree(0, n - 1, 1, x, y) << endl ; 
    }
    return 0;
}
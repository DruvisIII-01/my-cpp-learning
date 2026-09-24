#include <bits/stdc++.h>
using namespace std ;

#define int long long 

const int MAXN = 114514 ;
const int MAXM = 114514 ;
int n, m ;
int a[MAXN] ;
int sum[MAXN << 2] ;
int add[MAXN << 2] ;

void build(int l, int r, int i){
    if(l == r) {
        sum[i] = a[l] ;
        return ;
    }

    int mid = (l + r) / 2 ;
    build(l, mid, i * 2) ;
    build(mid + 1, r, i * 2 + 1) ;
    sum[i] = sum[i * 2] + sum[i * 2 + 1] ;
}

void lazy(int i, int n, int k){
    add[i] += k ;
    sum[i] += n * k ;
}

void down(int l, int r, int i){
    if(add[i]){
        int mid = (l + r) / 2 ;
        lazy(i * 2, mid - l + 1, add[i]) ;
        lazy(i * 2 + 1, r - mid, add[i]) ;
        add[i] = 0 ;
    }
}

int query(int jobl, int jobr, int l, int r, int i){
    // cout << '[' << l << ", " << r << ']' << endl ;
    if(l >= jobl && r <= jobr) return sum[i] ;
    if(l > jobr || r < jobl) return 0 ;
    down(l, r, i) ;

    int mid = (l + r) / 2 ;
    return query(jobl, jobr, l, mid, i * 2) + 
    query(jobl, jobr, mid + 1, r, i * 2 + 1) ;
}

void update(int jobl, int jobr, int l,int r, int i, int k){
    if(l >= jobl && r <= jobr) {
        sum[i] += (r - l + 1) * k ;
        add[i] += k ;
        return ;
    }if(l > jobr || r < jobl) return ;
    down(l, r, i) ;
    int mid = (l + r) / 2 ;
    update(jobl, jobr, l, mid, i * 2, k) ;
    update(jobl, jobr, mid + 1, r, i * 2 + 1, k) ;
    sum[i] = sum[i * 2 + 1] + sum[i * 2] ;
}

signed main() {
    cin >> n >> m ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    build(1, n, 1) ;
    // for(int t = 1 ; t <= n * 4 ; ++t) cout << sum[t] << ' ' ;
    // cout << endl ; 
    for(int t = 1 ; t <= m ; ++t){
        int op ; cin >> op ;
        if(op == 1) {
            int x, y, k ; cin >> x >> y >> k ;
            update(x, y, 1, n, 1, k) ;
        }else if(op == 2){
            int x, y ; cin >> x >> y ;
            cout << query(x, y, 1, n, 1) << endl; 
        }else{
            for(int t = 1 ; t <= n * 4 ; ++t) cout << sum[t] << ' ' ;
            cout << endl ;
        }
    }
    return 0;
}
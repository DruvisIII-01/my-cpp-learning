#include <bits/stdc++.h>
using namespace std ;

#define int long long
int n, q, m ; 
const int MAXN = 114514 ;

int a[MAXN] ;
int sum[MAXN << 2] ;
int mul[MAXN << 2] ;
int add[MAXN << 2] ;

void build(int l, int r, int i){
    if(l == r) sum[i] = a[l] ;
    else{
        int mid = (l + r) >> 1 ;
        build(l, mid, i << 1) ;
        build(mid + 1, r, i << 1 | 1) ;
    } 
}

void lazy1(int i, int k){
    sum[i] *= k ;
    mul[i] = k ;
}

void down1(int i){
    if(mul[i]){
        lazy1(i << 1, mul[i]) ;
        lazy1(i << 1 | 1, mul[i]) ;
        mul[i] = 0 ;
    }
}
void lazy2(int i, int n, int k){
    sum[i] += n * k ;
    add[i] = k ;
}

void down2(int l, int r, int i){
    if(add[i]){
        int mid = (l + r) >> 1 ;
        lazy2(i << 1, mid - l + 1, add[i]) ;
        lazy2(i << 1 | 1, r - mid, add[i]) ;
        add[i] = 0 ;
    }
}

int query(int jobl, int jobr, int l, int r, int i){
    if(l >= jobl && r <= jobr) return sum[i] ;
    if(l > jobr || r < jobl) return 0 ;
    down1() ;
    down2() ;
    
    int mid = (l + r) >> 1 ;
    return query(jobl, jobr, l, mid, i << 1) + 
    query(jobl, jobr, mid + 1, r, i << 1 | 1) ;
}

void update1(int jobl, int jobr, int k, int l, int r, int i){
    if(l >= jobl && r <= jobr) 
}

signed main() {
    cin >> n >> q >> m ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    build(1, n, 1) ;

    for(int T = 1 ; T <= q ; ++T){
        int op, x, y ; cin >> op >> x >> y ;
        if(op == 1){
            int k ; cin >> k ;
        }else if(op == 2){
            int k ; cin >> k ;
        }else if(op == 3){
            cout << query(x, y, 1, n, 1) << endl ;
        }else {
            for(int i = 1 ; i <= (n << 2) ; ++i) cout << sum[i] ;
            cout << endl ; 
        }
    }
    return 0;
}
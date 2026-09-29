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

        sum[i] = (sum[i << 1] + sum[i << 1 | 1]) % m ;
    } 
}

void down(int l, int r, int i){
    int ls = i << 1 ;
    int rs = i << 1 | 1 ;
    if(mul[i] != 1){
        mul[ls] = (mul[ls] * mul[i]) % m ;
        add[ls] = (add[ls] * mul[i]) % m ;
        sum[ls] = (sum[ls] * mul[i]) % m ;

        mul[rs] = (mul[rs] * mul[i]) % m ;
        add[rs] = (add[rs] * mul[i]) % m ;
        sum[rs] = (sum[rs] * mul[i]) % m ;

        mul[i] = 1 ;
    }if(add[i] != 0){
        int mid = (l + r) >> 1 ;
        int len1 = mid - l + 1 ;
        int len2 = r - mid ;

        add[ls] = (add[ls] + add[i]) % m ;
        sum[ls] = (sum[ls] + add[i] * len1) % m ;

        add[rs] = (add[rs] + add[i]) % m ;
        sum[rs] = (sum[rs] + add[i] * len2) % m ;

        add[i] = 0 ;
    }
}

int query(int jobl, int jobr, int l, int r, int i){
    if(l >= jobl && r <= jobr) return sum[i] ;
    if(l > jobr || r < jobl) return 0 ;

    down(l, r, i) ;
    
    int mid = (l + r) >> 1 ;
    return (query(jobl, jobr, l, mid, i << 1) + 
    query(jobl, jobr, mid + 1, r, i << 1 | 1) ) % m ;
}

void update(int jobl, int jobr, int toAdd, int toMul, int l, int r, int i){
    if(l >= jobl && r <= jobr) {
        sum[i] = (sum[i] * toMul + (r - l + 1) * toAdd) % m ;
        mul[i] = (mul[i] * toMul) % m ;
        add[i] = ((add[i] * toMul) + toAdd) % m ;  
        return ;
    }if(r < jobl || l > jobr) return ;

    down(l, r, i) ;

    int mid = (l + r) >> 1 ;
    update(jobl, jobr, toAdd, toMul, l, mid, i << 1 ) ;
    update(jobl, jobr, toAdd, toMul, mid + 1, r, i << 1 | 1) ;

    sum[i] = (sum[i << 1] + sum[i << 1 | 1] ) % m ;
}

signed main() {
    cin >> n >> q >> m ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    for(int t = 1 ; t <= (n << 2) ; ++t) mul[t] = 1 ;

    build(1, n, 1) ;

    for(int T = 1 ; T <= q ; ++T){
        int op, x, y ; cin >> op >> x >> y ;
        if(op == 1){
            int k ; cin >> k ;
            update(x, y, 0, k, 1, n, 1) ;
        }else if(op == 2){
            int k ; cin >> k ;
            update(x, y, k, 1, 1, n, 1) ;
        }else if(op == 3){
            cout << query(x, y, 1, n, 1) << endl ;
        }else {
            for(int i = 1 ; i <= (n << 2) ; ++i) cout << sum[i] << ' ' ;
            cout << endl ; 
        }
    }
    return 0;
}
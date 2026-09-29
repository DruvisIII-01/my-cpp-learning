#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 224524 ;

int tree[MAXN] ;
int a[MAXN] ;
int b[MAXN] ;
int n ;

int lowbit(int x) {return x & (-x) ;}

void add(int idx, int val){
    while(idx <= n){
        tree[idx] += val ;
        idx += lowbit(idx) ;
    }
}

int sum(int x){
    int res = 0 ;
    while(x > 0){
        res += tree[x] ;
        x -= lowbit(x) ;
    }
    return res ;
}

void solve(){
    cin >> n ;
    int ans = 0 ;
    memset(tree, 0, sizeof(tree)) ;
    memset(a, 0, sizeof(a)) ;
    memset(b, 0, sizeof(b)) ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        b[a[i]] ++ ;
    }
    for(int i = 1 ; i <= n ; i++) ans += (b[i] - 1) * b[i] / 2 ;
    for(int i = 1 ; i <= n ; i++) {
        ans += sum(n) - sum(a[i]) ;
        add(a[i], 1) ;
        // for(int j = 1 ; j <= n ; j++) {
        //     cout << tree[j] << ' ';
        // }cout << endl ;
    }
    cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
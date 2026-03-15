#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 224 ;

int a[MAXN][MAXN] ;
int cnt[MAXN*MAXN] ;

void solve(){
    int n ;cin >> n ;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++){
            cin >> a[i][j] ;
            cnt[a[i][j]]++ ;
        }
    }int mx = -1 ;
    for(int i = 1 ; i <= n*n ; i++) mx = max(mx, cnt[i]) ;
    if(mx <= n*(n-1)) cout << "YES" ;
    else cout << "NO" ;

    for(int i = 1 ; i <= n*n ; i++){
        cnt[i] = 0 ;
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
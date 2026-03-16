#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n+4) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    int left = 1 , right = n+1 ;
    int sa = a[1], sb = 0 ;
    int ta = a[1], tb = 0 ;
    int step = 1 ;
    while(right != left+1){
        bool b_eat = 0, a_eat = 0 ;
        while(tb <= ta && right > left+1){
            right-- ;
            sb += a[right] ;
            tb += a[right] ;
            b_eat = 1 ;
        }ta = 0 ;
        while(ta <= tb && right > left+1){
            left++ ;
            sa += a[left] ;
            ta += a[left] ;
            a_eat = 1 ;
        }tb = 0 ;
        step += a_eat+b_eat ;
    }cout << step << ' ' << sa << ' ' << sb ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
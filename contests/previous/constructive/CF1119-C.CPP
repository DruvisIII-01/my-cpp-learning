#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; scanf("%lld", &n) ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) scanf("%lld", &a[i]) ;

    //special judge
    int cnt_p = 0 ;
    int cnt_m = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        if(a[i] == 1) cnt_p++ ;
        else if(a[i] == -1) cnt_m++ ;
    }
    //cout << cnt_p << ' ' << cnt_m << endl ;
    if(!cnt_m){
        for(int i = 1 ; i <= n ; ++i) printf("%lld ", a[i]) ;
        return ;
    }else if(!cnt_p){
        if(cnt_m <= 1){
            for(int i = 1 ; i <= n ; ++i){
                if(a[i] == -1) a[i] = 1 ;
                printf("%lld ", a[i]) ;
            }
        }else{
            for(int i = 1 ; i <= n ; ++i){
                if(a[i] == -1) {
                    a[i] = 1 ;
                    break ;
                }
            }
            for(int i = n ; i >= 1 ; i--){
                if(a[i] == -1) {
                    a[i] = 1 ;
                    break ;
                }
            }
            for(int i = 1 ; i <= n ; ++i){
                if(a[i] == -1) a[i] = 0 ;
                printf("%lld ", a[i]) ;
            }
        }
        return ;
    }

    //general
    int L = -1 ;
    for(int i = 1 ; i <= n ; ++i){
        if(a[i] == 1){
            L = i ;
            break ;
        }
    }
    int R = -1 ;
    for(int i = n ; i >= 1 ; i--){
        if(a[i] == 1){
            R = i ; 
            break ;
        }
    }
    for(int i = L + 1 ; i < R ; ++i) if(a[i] == -1) a[i] = 0;
    bool fL = false ;
    for(int i = 1 ; i < L ; ++i){
        if(a[i] == -1) {
            if(!fL) {
                fL = true ;
                a[i] = 1 ;
            }else a[i] = 0 ;
        }
    }
    bool fR = false ;
    for(int i = n ; i >= 1 ; i--){
        if(a[i] == -1){
            if(!fR){
                fR = true ;
                a[i] = 1 ;
            }else a[i] = 0 ;
        }
    }
    for(int i = 1 ; i <= n ; ++i) printf("%lld ", a[i]) ;
}

signed main() {
    int T ;scanf("%lld", &T);
    while(T--) {
        solve() ;
        printf("\n") ;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

#define int long long

int calc(int x){
    if(!(x & 1)) return 0 ;
    int ans = 1 ;
    for(int turn = 1 ; turn <= 100 ; ++turn){
        ans <<= 1 ;
        if(!(ans & x)) return ans >> 1 ;
    }
    return -1 ;
}

void prt(int time){for(int i = 0 ; i <= time ; ++i) cout << i << ' ' ;}
void prt0(int time){for(int i = 1 ; i <= time ; ++i) cout << 0 << ' ' ;}

void solve(){
    int n, x ; cin >> n >> x ;
    if(!x) {
        prt0(n) ;
        return ;
    }
    int cmp = calc(x) ; // printf("cmp = %d\n", cmp) ;
    if((cmp << 1) > x){
        //if all cmp, then finish
        if(cmp < n){
            int tm = cmp + cmp - 1 ;
            if(tm >= n) prt(n - 1) ;
            else {
                prt(tm) ;
                prt0(n - 1 - tm) ;
            }
        }else{
            cout << x << ' ' ;
            prt(n - 2) ;
        }
    }else{
        //if surpass cmp, then not finish
        cout << x << ' ' ;
        if(cmp + 2 < n){
            int tm = cmp + cmp - 1 ;
            if(tm >= n - 1) prt(n - 2) ;
            else {
                prt(tm) ;
                prt0(n - tm - 2) ;
            }
        }else prt(n - 2) ;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
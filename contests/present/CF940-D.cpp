#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string op ; cin >> op ;
    if(n <= 2) {
        if(op[0] != op[1]){
            cout << "NO" ;
            return ;
        }
        cout << "RH" ;
        return ;
    }
    int E = 0, N = 0, W = 0, S = 0 ;
    for(char ch : op){
        if(ch == 'E') E++ ;
        else if(ch == 'W') W++ ;
        else if(ch == 'N') N++ ;
        else if(ch == 'S') S++ ;
    }
    if(abs(E - W) % 2 != 0 || abs(N - S) % 2 != 0){
        cout << "NO" ;
        return ;
    }
    
    string ans = "" ;
    //cout << "YES" << endl ;
    if(N >= S){
        if(W >= E){
            int dw = W - E, dn = N - S ;
            int cw = 0, cn = 0, ce = 0, cs = 0 ; 
            for(char ch : op){
                if(ch == 'N'){
                    cn++ ;
                    if(cn <= dn + 1) {
                        if(cn % 2 == 1) ans += 'R' ;
                        else ans += 'H' ;
                    }
                    else ans += 'H' ;
                }
                else if(ch == 'S'){
                    cs++ ;
                    if(cs == 1) ans += 'R' ;
                    else ans += 'H' ;
                }
                else if(ch == 'W'){
                    cw++ ;
                    if(cw <= dw + 1) {
                        if(cw % 2 == 1) ans += 'H' ;
                        else ans += 'R' ;
                    }
                    else ans += 'R' ;
                }
                else if(ch == 'E'){
                    ce++ ;
                    if(ce == 1) ans += 'H' ;
                    else ans += 'R' ;
                }
            }
        }
        else{
            int de = E - W, dn = N - S ;
            int cw = 0, cn = 0, ce = 0, cs = 0 ; 
            for(char ch : op){
                if(ch == 'N'){
                    cn++ ;
                    if(cn <= dn + 1) {
                        if(cn % 2 == 1) ans += 'R' ;
                        else ans += 'H' ;
                    }
                    else ans += 'H' ;
                }
                else if(ch == 'S'){
                    cs++ ;
                    if(cs == 1) ans += 'R' ;
                    else ans += 'H' ;
                }
                else if(ch == 'W'){
                    cw++ ;
                    if(cw == 1) ans += 'H' ;
                    else ans += 'R' ;
                }
                else if(ch == 'E'){
                    ce++ ;
                    if(ce <= de + 1){
                        if(ce % 2 == 1) ans += 'H' ;
                        else ans += 'R' ;
                    }
                    else ans += 'R' ;
                }
            }
        }
    }
    else{
        if(W >= E){
            int ds = S - N, dw = W - E ;
            int cw = 0, cn = 0, ce = 0, cs = 0 ; 
            for(char ch : op){
                if(ch == 'N'){
                    cn++ ;
                    if(cn == 1) ans += 'R' ;
                    else ans += 'H' ;
                }
                else if(ch == 'S'){
                    cs++ ;
                    if(cs <= ds + 1){
                        if(cs % 2 == 1) ans += 'R';
                        else ans += 'H' ;
                    }
                    else ans += 'H' ;
                }
                else if(ch == 'W'){
                    cw++ ;
                    if(cw <= dw + 1) {
                        if(cw % 2 == 1) ans += 'H' ;
                        else ans += 'R' ;
                    }
                    else ans += 'R' ;
                }
                else if(ch == 'E'){
                    ce++ ;
                    if(ce == 1) ans += 'H' ;
                    else ans += 'R' ;
                }
            }
        }
        else{
            int de = E - W, ds = S - N ;
            int cw = 0, cn = 0, ce = 0, cs = 0 ; 
            for(char ch : op){
                if(ch == 'N'){
                    cn++ ;
                    if(cn == 1) ans += 'R' ;
                    else ans += 'H' ;
                }
                else if(ch == 'S'){
                    cs++ ;
                    if(cs <= ds + 1){
                        if(cs % 2 == 1) ans += 'R';
                        else ans += 'H' ;
                    }
                    else ans += 'H' ;
                }
                else if(ch == 'W'){
                    cw++ ;
                    if(cw == 1) ans += 'H' ;
                    else ans += 'R' ;
                }
                else if(ch == 'E'){
                    ce++ ;
                    if(ce <= de + 1){
                        if(ce % 2 == 1) ans += 'H' ;
                        else ans += 'R' ;
                    }
                    else ans += 'R' ;
                }
            }
        }
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
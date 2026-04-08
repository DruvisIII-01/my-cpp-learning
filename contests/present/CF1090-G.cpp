#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int Mod = 676767677 ;

void solve(){
    //initialize
    int n, m ; cin >> n >> m ;
    vector <int> b(n + 1) ;
    vector <int> hsh(m + 1) ;
    vector <int> pre(m + 1) ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> b[i] ;
        hsh[b[i]]++ ;
    }
    pre[0] = hsh[0] ;
    for(int i = 1 ; i < m ; i++){
        pre[i] = pre[i - 1] + hsh[i] ;
    }
    
    //special judge
    bool check = true ;
    for(int i = 1 ; i <= n ; i++){
        if(b[i] == 0) continue ;
        if(i == 1){
            if(b[i] > b[i + 1]) continue ;
            else {
                check = false ;
                break ;
            }
        }if(i == n){
            if(b[i] > b[i - 1]) continue ;
            else {
                check = false ;
                break ;
            }
        }if(b[i] <= b[i - 1] && b[i] <= b[i + 1]){
            check = false ;
            break ;
        }
    }if(!check) {
        cout << 0 ; 
        return ;
    }

    int ans = 1 ;
    for(int i = 1 ; i <= n ; i++){
        if(b[i] == 0) continue ; 
        int t = b[i] ;
        if(i == 1){
            if(b[i + 1] == t - 1) {
                ans *= pre[t - 1] ;
                ans %= Mod ;
            }else {
                ans *= hsh[t - 1] ;
                ans %= Mod ;
            }
            continue ;
        }if(i == n){
            if(b[i - 1] == t - 1) {
                ans *= pre[t - 1] ;
                ans %= Mod ;
            }else {
                ans *= hsh[t - 1] ;
                ans %= Mod ;
            }
            continue ;
        }
        if(b[i + 1] >= t - 1 && b[i - 1] >= t - 1) {
            ans *= pre[t - 1] ;
            ans %= Mod ;
        }else {
            ans *= hsh[t - 1] ;
            ans %= Mod ;
        }
    }cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
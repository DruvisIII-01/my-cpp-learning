#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;  
    string a ; cin >> a ; a = '*' + a ;
    string b ; cin >> b ; b = '*' + b ; 
    
    bool perfect = true ;
    for(int i = 1 ; i <= n ; ++i){
        if(a[i] != b[i]) {
            perfect = false ;
            break ;
        }
    }if(perfect) {
        cout << "YES" ;
        return ;
    }

    int cnta = 0 ;
    int cntb = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        cnta += (a[i] == '1') ;
        cntb += (b[i] == '1') ;
    }if(cnta != cntb || n < 3){
        cout << "NO" ;
        return ;
    }

    int tot1 = 0 ;
    int tot2 = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        if(i % 2 == 0) continue ;
        tot1 += (a[i] == '1') ;
        tot2 += (b[i] == '1') ;
    }
    if(tot1 == tot2) cout << "YES" ;
    else cout << "NO" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
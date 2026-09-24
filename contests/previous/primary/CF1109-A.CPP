#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;
    
    int mx = 0 ;
    int cur = 0 ;
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == '*'){
            mx = max(mx, cur) ;
            cur = 0 ;
        }else{
            cur++ ;
            if(i == n - 1) mx = max(mx, cur) ; 
        }
    }cout << (mx + 1) / 2 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    string s ; cin >> s ; s = '*' + s ;
    int t = n / k ; int ans = 0 ;
    for(int i = 0 ; i < t ; i++){
        bool has_zero = false ;
        for(int j = 1 ; j <= k ; j++){
            if(s[i * k + j] == '0'){
                has_zero = true ;
                break ;
            }
        }ans += has_zero ;
    }cout << t - ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
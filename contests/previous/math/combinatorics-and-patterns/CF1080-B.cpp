#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool is_2power(int x) {
    return (x > 0) && ((x & (x - 1)) == 0) ;
}

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    vector<int> b(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        b[a[t]] = t ;
    }
    // for(int t = 1 ; t <= n ; ++t) cout << b[t] << ' ' ;
    // cout << endl ;

    bool ans = true ;
    for(int t = 1 ; t <= n ; ++t) {
        //printf("b[t] = %d t = %d\n", b[t], t) ;
        if(b[t] <= t){
            if((t % b[t]) != 0 || !(is_2power(t / b[t]))){
                ans = false ;
                break ;
            } 
        }else{
            if((b[t] % t) != 0 || !(is_2power(b[t] / t))){
                ans = false ;
                break ;
            } 
        }
    }if(ans) cout << "YES" ;
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
#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int a, b, c ; cin >> a >> b >> c ; 
    int m = min(a, min(b, c)), M = max(a, max(b, c)) ;
    int Mm = a + b + c - m - M ; 
    if(Mm + 1 == M && m + 1 == Mm) cout << "YES" ;
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
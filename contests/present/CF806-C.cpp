#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;
    
    vector<int> b(n + 1) ;
    vector<string> stp(n + 1) ;
    for(int t = 1 ; t <= n ; ++t){
        cin >> b[t] >> stp[t] ;
        int add = 0 ;
        for(char ch : stp[t]){
            if(ch == 'D') add++ ;
            else if(ch == 'U') add-- ;
        }cout << (a[t] + add + 100000) % 10 << ' ' ;
    } 
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
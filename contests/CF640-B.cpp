#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ;cin >> n >> k ;
    // if(k > n || (n%k)%2 == 1) {
    //     cout << "NO" ;
    //     return ;
    // }cout << "YES" << endl ;
    // vector <int> a(k+1,n/k) ;
    // a[k] += n%k ;
    // for(int i = 1 ; i <= k ; i++) cout << a[i] << ' ' ;
    if(k > n) {
         cout << "NO" ;
         return ;
    }
    int t1 = n-(k-1) ;
    int t2 = n-(k-1)*2 ;
    //cout << t1 << ' ' << t2 << endl ;
    if(t1%2 == 0 && (t2%2 == 1 || t2 <= 0)){
           cout << "NO" ;
           return ;
    }
    // vector <int> a(k+1) ;
    if(t1%2 == 1){
        cout << "YES" << endl ;
        for(int i = 1 ; i < k ; i++) cout << '1' << ' ' ;
        cout << t1 ;
        return ;
    }
    cout << "YES" << endl ;
    for(int i = 1 ; i < k ; i++) cout << '2' << ' ' ;
    cout << t2 ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
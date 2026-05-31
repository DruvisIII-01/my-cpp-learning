#include <bits/stdc++.h>
using namespace std ;

#define int long long

int n ; 

void solve(){
    cin >> n ;
    vector <int> a(n + 123) ;
    map <int, priority_queue<int, vector<int>, greater<int>>> mp ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    for(int i = 1 ; i <= n ; i++) {
        int mk = a[i] >> 2 ;
        mp[mk].push(a[i]) ;
    }
    for(int i = 1 ; i <= n ; i++) {
        int mk = a[i] >> 2 ;
        int tmp = mp[mk].top() ;
        cout << tmp << ' ' ;
        mp[mk].pop() ;
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
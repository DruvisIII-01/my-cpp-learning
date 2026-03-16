#include <bits/stdc++.h>
using namespace std ;

//#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n+1, 0) ;
    vector <int> pre(n+1, 0) ;
    vector <bool> vis(n+1, 0) ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
        pre[i] = pre[i-1]+a[i] ;
    }
    for(int left = 1 ; left < n ; left++){
        for(int right = left+1 ; right <= n ; right++){
            int tmp = pre[right]-pre[left-1] ;
            if(tmp > n) break ;
            vis[tmp] = 1 ;
        }
    }
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        ans += vis[a[i]] ;
    }
    cout << ans ;
    pre.clear() ;
    vis.clear() ; 
}

int main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0 ;
}
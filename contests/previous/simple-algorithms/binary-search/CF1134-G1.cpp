#include <bits/stdc++.h>
using namespace std ;

#define int long long

int k, n ;
int dist(int i, int j){
    if(i < j) swap(i, j) ;
    return min(i - j, n - i + j) ;
}
bool check(int D, vector<int>& g){
    vector<int> h1(n + 2), h2(n + 2), G(n + 1) ;
    h1[1] = h1[n + 1] = g[n + 1] ;
    for(int t = 2 ; t <= n ; ++t) h1[t] = max(g[t], h1[t - 1] - D) ;
    h2[1] = h2[n + 1] = g[n + 1] ;
    for(int t = n ; t >= 1 ; t--) h2[t] = max(g[t], h2[t + 1] - D) ;
    for(int t = 1 ; t <= n ; ++t) G[t] = max(h1[t], h2[t]) ;

    int res = 0 ;
    for(int t = 1 ; t <= n ; ++t) {
        res += G[t] - g[t] ;
        if(res > k) return false ;  
    }
    return res <= k ;
}

void solve(){
    //直接A了G2，G1买一送一
    cin >> n >> k ; 
    vector<int> a(n + 1) ; for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    //find the mx of array and its idx
    int mx = -1, mx_id = -1 ;
    for(int t = 1 ; t <= n ; ++t) {
        if(a[t] > mx){
            mx = a[t]l ;
            mx_id = t ;
        }
    }
    //rotate the array to make the mx to be first
    vector<int> g(n + 3) ;
    for(int t = mx_id ; t <= n ; ++t) g[t - mx_id + 1] = a[t] ;
    for(int t = 1 ; t < mx_id ; ++t) g[t + n - mx_id + 1] = a[t] ;
    g[n + 1] = a[mx_id] ; 

    //find the left and right bond of binary-search
    int left = -1, right = mx ;
    while(left + 1 != right){
        int mid = (left + right) >> 1 ;
        if(check(mid, g)) right = mid ; 
        else left = mid ;
    }cout << right ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
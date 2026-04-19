#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool is_prime(int x){
    if(x == 1) return false ;
    if(x == 2) return true ;
    if(x % 2 == 0) return false ;
    for(int i = 3 ; i * i <= x ; i += 2){
        if(x % i == 0) return false ;
    }return true ;
}

int vpn(int p , int n){
    int cnt = 0 ;
    while(n % p == 0){
        n = n / p ;
        cnt++ ;
    }return cnt ;
}

void solve(){
    int n ; cin >> n ;
    vector <int> yin ;
    vector <int> su_yin ;
    for(int i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            yin.push_back(i) ;
            if(i * i < n) yin.push_back(n / i) ;
        }
    }
    for(auto x : yin) if(is_prime(x)) su_yin.push_back(x) ;
    
    map <int, int> time ;
    int mx = 0 ;
    for(auto x : su_yin){
        time[x] = vpn(x, n) ;
        mx = max(mx, time[x]) ;
    }

    vector <int> ans(mx, 1) ;
    for(auto p : su_yin){
        for(int i = mx - 1 ; i >= mx - time[p] ; i--){
            ans[i] *= p ;
        }
    }cout << mx << endl ;
    for(auto x : ans) cout << x << ' ' ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
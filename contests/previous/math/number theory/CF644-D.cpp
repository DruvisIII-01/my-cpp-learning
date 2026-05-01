#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, k ; cin >> n >> k ;
    vector <int> yin ;
    for(int i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            yin.push_back(i) ;
            if(i * i < n) yin.push_back(n / i) ;
        }
    }sort(yin.begin(), yin.end()) ;
    int sz = yin.size() ;
    for(int i = 0 ; i < sz ; i++){
        if(yin[i] > k){
            cout << n / yin[i - 1] ;
            return ;
        }
    }cout << n / yin[sz - 1] ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
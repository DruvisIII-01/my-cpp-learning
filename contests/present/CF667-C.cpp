#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, x, y ; cin >> n >> x >> y ;
    int D = y - x ;
    vector <int> yin ;
    for(int i = 1 ; i * i <= D ; i++){
        if(D % i == 0){
            yin.push_back(i) ;
            if(i * i < D) yin.push_back(D / i) ;
        }
    }sort(yin.begin(), yin.end()) ;
    for(auto d : yin){
        if(1 + D / d > n) continue ;
        if(y / d >= n) {
            for(int i = n - 1 ; i >= 0 ; i--){
                cout << y - i * d << ' ' ;
            }return ;
        }else{
            if(y % d == 0){
                for(int i = 1 ; i <= n ; i++){
                    cout << i * d << ' ' ;
                }return ;
            }
            for(int i = 0 ; i < n ; i++){
                cout << i * d + y % d << ' ' ;
            }return ;
        }
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
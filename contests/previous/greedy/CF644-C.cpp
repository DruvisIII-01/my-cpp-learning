#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    vector <int> odds ;
    vector <int> evens ;
    int odd = 0, even = 0 ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        if(a[i] % 2){
            odd++ ;
            odds.push_back(a[i]) ;
        }else{
            even++ ;
            evens.push_back(a[i]) ;
        }
    }if(odd % 2 == 0 && even % 2 == 0){
        cout << "YES" ;
        return ;
    }for(auto x : odds){
        for(auto y : evens){
            if(abs(x - y) == 1){
                cout << "YES" ;
                return ;
            }
        }
    }cout << "NO" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
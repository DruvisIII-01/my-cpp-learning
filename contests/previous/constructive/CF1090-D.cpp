#include <bits/stdc++.h>
using namespace std ;

#define int long long

map <int, int> prime ;

bool is_prime(int x){
    if(x == 1) return false ;
    if(x == 2) return true ;
    if(x % 2 == 0) return false ;
    for(int i = 3 ; i*i <= x ; i++){
        if(x % i == 0) return false ;
    }return true ;
} 

void construct(){
    prime[0] = 1 ;
    int index = 1 ;
    int num = 2 ;
    while(index <= 1e4 + 5){
        if(is_prime(num)){
            prime[index] = num ;
            index++ ;
        }
        num++ ;
    }
}

void solve(){
    int n ; cin >> n ;
    for(int i = 1 ; i <= n ; i++){
        cout << prime[i - 1] * prime[i] << ' ' ;
    }
}

signed main() {
    int T ;cin >> T ;
    construct() ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

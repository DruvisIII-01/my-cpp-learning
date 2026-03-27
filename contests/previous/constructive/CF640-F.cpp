#include <bits/stdc++.h>
using namespace std ;

#define int long long

void Printg (int time, int value){
    for(int i = 1 ; i <= time ; i++) cout << value ;
}

void solve(){
    int n0, n1, n2 ; cin >> n0 >> n1 >> n2 ;
    if(n1 == 0){
        if(n2 > 0) {
            Printg(n2 + 1, 1) ;
            return ;
        }
        if(n0 > 0) {
            Printg(n0 + 1, 0) ;
            return ;
        }
    }
    Printg(n2 + 1, 1) ;
    Printg(n0 + 1, 0) ;
    if(n1 % 2 == 1) Printg((n1 - 1) / 2, 10) ;
    else {
        Printg(n1 / 2 - 1, 10) ;
        cout << 1 ;
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
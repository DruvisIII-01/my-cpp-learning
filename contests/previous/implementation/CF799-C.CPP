#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    vector <string> desk(10, "88888888") ;
    for(int i = 1 ; i <= 8 ; i++){
        for(int j = 1 ; j <= 8 ; ++j){
            char chr = 'p' ; cin >> chr ;
            desk[i][j] = chr ;
        }
    }
    for(int i = 2 ; i <= 7 ; ++i){
        for(int j = 2 ; j <= 7 ; ++j){
            if(desk[i][j] == '.') continue ;
            if(desk[i + 1][j + 1] == '#' &&
            desk[i + 1][j - 1] == '#' &&
            desk[i - 1][j + 1] == '#' &&
            desk[i - 1][j - 1] == '#'){
                cout << i << ' ' << j ;
                return ;
            }
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
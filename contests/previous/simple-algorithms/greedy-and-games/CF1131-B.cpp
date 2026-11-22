#include <bits/stdc++.h>
using namespace std ;

#define int long long

void _print(int time, char ch){
    for(int t = 1 ; t <= time ; ++t) cout << ch ;
}

void solve(){
    int x, y, z ; cin >> x >> y >> z ;
    if(x >= max(y, z)) _print(x + y + z, 'P') ;
    else if(y >= max(z, x)) _print(x + y + z, 'R') ;
    else if(z >= max(x, y)) _print(x + y + z, 'S') ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
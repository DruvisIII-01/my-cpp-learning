#include <bits/stdc++.h>
using namespace std ;

int n ; 

bool judge (int x){
    if(x <= 1) return false ;
    if((x & (x - 1)) == 0) return false ;
    if(((x + 1) & x) == 0) return false ; 
    return true ;
}

int calc(int x){
    int res = 1 ;
    while(res & x){
        res <<= 1 ;
    }return res ;
}

void solve(){
    cin >> n ; 
    if(!judge(n)) {cout << "-1" ; return ; }

    int s = (int)(log2(1.0 * n)) ;
    int ans = calc(n) ;
    cout << n - (1 << s) + ans ; 
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
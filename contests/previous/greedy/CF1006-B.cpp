#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ;
    int cnt1 = 0 ;//count the chr '_'
    int cnt2 = 0 ;//count the chr '-'
    for(char ch : s){
        cnt1 += (ch == '_') ;
        cnt2 += (ch == '-') ;
    }
    cout << cnt1 * (cnt2 - cnt2 / 2) * (cnt2 / 2) ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
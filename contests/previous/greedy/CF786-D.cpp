#include <bits/stdc++.h>
using namespace std ;

#define int long long

//ub

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;
    s = s + 'W' ;
    bool cnt[2] = {0};
    for(char ch : s){
        if(ch == 'W') {
            if ((!cnt[1] && cnt[0]) || (!cnt[0] && cnt[1] )){
                cout << "NO" ;
                return ;
            }
            cnt[1] = 0 ;
            cnt[0] = 0 ;
        }
        else if(ch == 'R') {
            cnt[1] = 1 ;
        }else cnt[0] = 1 ;
    }
    cout << "YES" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
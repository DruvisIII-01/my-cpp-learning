#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string s ; cin >> s ;
    stack <int> stk ;
    for(int i = 0 ; i < n ; i++){
        int cur = -1 ;
        if(s[i] == ')') cur = 1 ;
        else cur = 0 ; 
        if(stk.empty()) stk.push(cur) ;
        else {
            int tp = stk.top() ;
            if(tp != cur) stk.pop() ;
            else stk.push(cur) ;
        }
    }if(stk.empty()) cout << "YES" ;
    else cout << "NO" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
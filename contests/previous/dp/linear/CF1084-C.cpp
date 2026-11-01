#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ;
    stack<char> stk ;
    for(char ch : s){
        if(stk.empty()) stk.push(ch) ;
        else{
            char tp = stk.top() ;
            if(tp == ch) stk.pop() ;
            else stk.push(ch) ;
        }
    }
    if(stk.empty()) cout << "YES" ;
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
#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    string n ; cin >> n ;
    int s ; cin >> s ; 
    int sum = 0 ;
    for(char ch : n){
        sum += (int) (ch - '0') ;
    }//int tmp = sum ;
    if(sum <= s) {
        cout << 0 ;
        return ;
    }int l = n.size() ;
    unsigned long long n1 = stoull(n) ;
    for(int i = 1 ; i <= l ; i++){
        int mod = (int) pow(10, i) ;
        unsigned long long old = n1, ne = (n1 / mod + 1) * mod ;
        string nes = to_string(ne) ;
        int new_sum = 0 ;
        for(char ch : nes){
            new_sum += (int) (ch - '0') ;
        }if(new_sum <= s){
            cout << ne - old ;
            return ;
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
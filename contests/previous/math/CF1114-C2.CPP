#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    string a ; cin >> a ; a = '*' + a ;
    string b ; cin >> b ; b = '*' + b ;

    bool perfect = true ;
    for(int i = 1 ; i <= n ; ++i){
        if(a[i] != b[i]) {
            perfect = false ;
            break ;
        }
    }if(perfect){
        cout << '0' ;
        return ;
    }

    int cnta = 0 ; 
    int cntb = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        cnta += (a[i] == '1') ;
        cntb += (b[i] == '1') ;
    }if(cnta != cntb || n < 3){
        cout << "-1" ;
        return ;
    }

    int tota = 0 ;
    int totb = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        if(i % 2 == 0) continue ;
        tota += (a[i] == '1') ;
        totb += (b[i] == '1') ;  
    }if(tota != totb){
        cout << "-1" ;
        return ;
    }

    vector<int> a_odd ;
    vector<int> b_odd ;
    vector<int> a_even ;
    vector<int> b_even ;
    for(int i = 1 ; i <= n ; ++i){
        if(i % 2){
            if(a[i] == '1') a_odd.push_back((i + 1) / 2) ;
            if(b[i] == '1') b_odd.push_back((i + 1) / 2) ;
        }
        else{
            if(a[i] == '1') a_even.push_back(i / 2) ;
            if(b[i] == '1') b_even.push_back(i / 2) ;
        }
    }
    int ans = 0 ;
    for(int i = 0 ; i < a_even.size() ; ++i) ans += abs(a_even[i] - b_even[i]) ;
    for(int i = 0 ; i < a_odd.size() ; ++i) ans += abs(a_odd[i] - b_odd[i]) ;
    cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
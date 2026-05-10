#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> even ;
    vector <int> odd ;
    int A, B ; A = B = 0 ;
    for(int t = 1 ; t <= n ; t++) {
        int x ; cin >> x ;
        if(x % 2 == 1) odd.push_back(x) ;
        else even.push_back(x) ;
    }
    sort(odd.begin(), odd.end()) ;
    sort(even.begin(), even.end()) ;
    for(int t = 1 ; t <= n ; t++){
        int sz1 = even.size(), sz2 = odd.size() ;
        int mx_e = -1, mx_o = -1 ;
        if(sz1) mx_e = even[sz1 - 1] ;
        if(sz2) mx_o = odd[sz2 - 1] ;
        if(t % 2 == 1){
            //Alice's turn, even is valid
            if(mx_e > mx_o) {
                even.pop_back() ;
                A += mx_e ;
            }else odd.pop_back() ;
        }else{
            //Bob's turn, odd is valid
            if(mx_o > mx_e) {
                odd.pop_back() ;
                B += mx_o ;
            }else even.pop_back() ;
        }
    }
    if(A > B) cout << "Alice" ;
    else if(A < B) cout << "Bob" ;
    else cout << "Tie" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
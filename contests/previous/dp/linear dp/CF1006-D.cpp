#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] ;

    //special judge 
    bool increased = true ; 
    for(int i = 2 ; i <= n ; ++i){
        if(a[i] < a[i - 1]) { increased = false ; break ;}
    }if(increased) {cout << '1' << ' ' << '1' ; return ;}

    vector <vector <int>> ta(n + 1, vector<int>(n + 1, 0)) ;
    vector <vector <int>> tb(n + 1, vector<int>(n + 1, 0)) ;
    for(int i = 1 ; i <= n ; ++i){
        ta[i][i] = tb[i][i] = 0 ;
        for(int j = 1 + i ; j <= n ; ++j){
            ta[i][j] = ta[i][j - 1] + (a[j] > a[i]) ;
            tb[i][j] = tb[i][j - 1] + (a[j] < a[i]) ;
        }
    }
    
    int mx = -1 ; 
    int mx_l = -1, mx_r = -1 ;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            int cur = tb[i][j] - ta[i][j] ;
            if(cur > mx){
                mx = cur ; 
                mx_l = i ; 
                mx_r = j ; 
            }
        }
    }

    cout << mx_l << ' ' << mx_r ; 
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
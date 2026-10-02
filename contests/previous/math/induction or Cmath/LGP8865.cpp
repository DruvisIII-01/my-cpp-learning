#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 998244353 ;

void Print(int n, int m, vector<vector<int>>&a){
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j)
        cout << a[i][j] << ' ' ;
        cout << endl ;
    }cout << endl ;
    cout << endl ;
}
void solve(){
    int n, m, c, f ; cin >> n >> m >> c >> f ;
    vector<string> mp ;
    mp.push_back("*") ;
    for(int t = 1 ; t <= n ; ++t){
        string s ; cin >> s ;
        s = '*' + s ; 
        mp.push_back(s) ;
    }

    vector<vector<int>> aft(n + 1, vector<int>(m + 1)) ;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = m - 1 ; j >= 1 ; j--){
            if(mp[i][j] == '1' || mp[i][j + 1] == '1') aft[i][j] = 0 ;
            else {
                aft[i][j] = aft[i][j + 1] + 1 ;
                aft[i][j] %= mod ;
            }
        }
    }
    //Print(n, m, aft) ;

    vector<vector<int>> down(n + 1, vector<int>(m + 1)) ;
    for(int j = 1 ; j <= m ; ++j){
        for(int i = 1 ; i <= n ; ++i){
            if(mp[i][j] == '0') {
                down[i][j] = down[i - 1][j] + aft[i][j] ;
                down[i][j] %= mod ;
            }else down[i][j] = 0 ;
        }
    }
    //Print(n, m, down) ;

    int ansC = 0 ;
    vector<vector<int>> curC(n + 1, vector<int>(m + 1)) ;
    for(int j = 1 ; j <= m ; ++j){
        for(int i = 3 ; i <= n ; ++i){
            if(mp[i][j] == '1' || mp[i - 1][j] == '1'){
                curC[i][j] = 0 ;
                continue ;
            }
            curC[i][j] = down[i - 2][j] * aft[i][j] ;
            curC[i][j] %= mod ;
            ansC += curC[i][j] ;
            ansC %= mod ;
        }
    }

    vector<vector<int>> dwn(n + 1, vector<int>(m + 1)) ;
    for(int j = 1 ; j <= m ; ++j){
        for(int i = n - 1 ; i >= 1 ; i--){
            if(mp[i][j] == '1' || mp[i + 1][j] == '1') dwn[i][j] = 0 ;
            else {
                dwn[i][j] = dwn[i + 1][j] + 1 ;
                dwn[i][j] %= mod ;
            }
        }
    }

    int ansF = 0 ;
    for(int j = 1 ; j <= m ; ++j){
        for(int i = 3 ; i <= n ; ++i){
            ansF += dwn[i][j] * curC[i][j] ;
            ansF %= mod ;
        }
    }

    cout << c * ansC % mod << ' ' << f * ansF % mod ;
}

signed main() {
    int T, id ;cin >> T >> id ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
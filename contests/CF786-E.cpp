#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    int cnt[26][26] ;
    for(int i = 0 ; i < 26 ; i++){
        for(int j = 0 ; j < 26 ; j++){
            cnt[i][j] = 0 ;
        }
    }
    vector <string> ss(n + 1) ;
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++){
        cin >> ss[i] ;
        for(int j = 0 ; j < 26 ; j++){
            if(j + 'a' == ss[i][0]) continue ;
            ans += cnt[j][ss[i][1] - 'a'] ;
        }
        for(int j = 0 ; j < 26 ; j++){
            if(j + 'a' == ss[i][1]) continue ;
            ans += cnt[ss[i][0] - 'a'][j] ;
        }
        cnt[ss[i][0] - 'a'][ss[i][1] - 'a']++ ;
    }cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
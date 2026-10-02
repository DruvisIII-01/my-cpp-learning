#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int h, w ; cin >> h >> w ;
    vector<string> strs ;
    strs.push_back("*") ;
    for(int t = 1 ; t <= h ; ++t){
        string s ; cin >> s ; s = '*' + s ;
        strs.push_back(s) ;
    }

    //转置
    //(mp[i][j] == 1) <=> strs[i][j] is white
    int m = min(h, w), n = h + w - m ;
    vector<vector<int>> mp(m + 1, vector<int>(n + 1)) ;
    for(int i = 1 ; i <= m ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(h <= w) mp[i][j] = (strs[i][j] == '.') ;
            else mp[i][j] = (strs[j][i] == '.') ; 
        }
    }

    // cout << endl ;
    // for(int i = 1 ; i <= m ; ++i){
    //     for(int j = 1 ; j <= n ; ++j) {
    //         cout << mp[i][j] << ' ' ;
    //     }cout << endl ;
    // }cout << endl ;

    //(pref[i][j] = x) <=> mp[1][j] to mp[i][j] has x white cells 
    vector<vector<int>> pref(m + 1, vector<int>(n + 1)) ;
    for(int j = 1 ; j <= n ; ++j){
        for(int i = 1 ; i <= m ; ++i){
            pref[i][j] = pref[i - 1][j] + mp[i][j] ;
        }
    }

    // cout << endl ;
    // for(int i = 1 ; i <= m ; ++i){
    //     for(int j = 1 ; j <= n ; ++j) {
    //         cout << pref[i][j] << ' ' ;
    //     }cout << endl ;
    // }cout << endl ;

    int ans = 0 ;
    for(int U = 1 ; U <= m ; ++U){
        for(int D = U ; D <= m ; ++D){
            //(col_ok[i] == true) <=> col i has at least 1 white cell
            vector<bool> col_ok(n + 1) ;
            for(int i = 1 ; i <= n ; ++i){
                col_ok[i] = ((pref[D][i] - pref[U - 1][i]) > 0) ;
            }
            //(aft[i] == x) <=> form col i to n has x valid cols
            vector<int> aft(n + 2) ;
            for(int i = n ; i >= 1 ; i--){
                aft[i] = aft[i + 1] + col_ok[i] ;
            }
            int right = 1 ;
            int cnt1 = mp[U][1], cnt2 = mp[D][1] ;
            for(int left = 1 ; left <= n ; ++left){
                if(!col_ok[left]){
                    cnt1 -= mp[U][left] ;
                    cnt2 -= mp[D][left] ;
                    continue ; 
                }
                if(right < left) {
                    right = left ;
                    cnt1 += mp[U][right] ;
                    cnt2 += mp[D][right] ; 
                }
                while((!cnt1 || !cnt2) && right <= n){
                    right++ ;
                    if(right <= n){
                        cnt1 += mp[U][right] ;
                        cnt2 += mp[D][right] ; 
                    }
                }
                ans += aft[right] ;
                cnt1 -= mp[U][left] ;
                cnt2 -= mp[D][left] ; 
            }
        }
    }
    cout << ans + 1 ;
    return 0;
}
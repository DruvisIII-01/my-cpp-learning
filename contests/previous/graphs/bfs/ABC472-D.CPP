#include <bits/stdc++.h>
using namespace std ;

//#define int long long
const int vx[4] = {1, -1, 0, 0} ;
const int vy[4] = {0, 0, 1, -1} ;

signed main() {
    int h, w, k ; cin >> h >> w >> k ;
    vector<string> mp ;
    for(int t = 1 ; t <= h ; ++t){
        string s ; cin >> s ;
        mp.push_back(s) ;
    }

    vector<bool> badC(w) ;
    vector<bool> badR(h) ;
    for(int i = 0 ; i < h ; ++i){
        for(int j = 0 ; j < w ; ++j){
            if(mp[i][j] == '#'){
                badC[j] = true ;
                badR[i] = true ;
            }
        }
    }

    vector<int> safeC ;
    for(int j = 0 ; j < w ; ++j)
    if(!badC[j]) safeC.push_back(j) ;
    vector<int> safeR ;
    for(int i = 0 ; i < h ; ++i)
    if(!badR[i]) safeR.push_back(i) ;

    // cout << safeR.size() << ' ' << safeC.size() << endl ;
    // for(int i = 0 ; i < safeR.size() ; ++i){
    //     for(int j = 0 ; j < safeC.size() ; ++j){
    //         cout << '(' <<safeR[i] << ", "<< safeC[j] << "), " ; 
    //     }
    // }
    //cout << endl ;cout << endl ;cout << endl ;

    vector<vector<int>> dp(h, vector<int>(w, -1)) ;
    queue<pair<int, int>> que ;
    for(int i = 0 ; i < safeR.size() ; ++i){
        for(int j = 0 ; j < safeC.size() ; ++j){
            dp[safeR[i]][safeC[j]] = 0 ;
            que.push(make_pair(safeR[i], safeC[j])) ;
        }
    }
    while(!que.empty()){
        pair<int, int> pii = que.front() ;
        int px = pii.first, py = pii.second ;
        for(int t = 0 ; t < 4 ; ++t){
            int nx = px + vx[t], ny = py + vy[t] ; 
            if(nx < 0 || nx >= h || ny < 0 || ny >= w
            || dp[nx][ny] != -1 || mp[nx][ny] == '#'
            || dp[px][py] == k) continue ;

            dp[nx][ny] = dp[px][py] + 1 ;
            que.push(make_pair(nx, ny)) ;
        }
        que.pop() ;
    }

    int ans = 0 ;
    for(int i = 0 ; i < h ; ++i){
        for(int j = 0 ; j < w ; ++j){
            ans += (dp[i][j] != -1) ;
            // cout << dp[i][j] << ' ' ;
        }// cout << endl ;
    }cout << ans ;
    return 0;
}
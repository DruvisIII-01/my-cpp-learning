#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int n, s, l ; cin >> n >> s >> l ;
    vector<int> a(n) ;
    for(int i = 1 ; i < n ; ++i) cin >> a[i] ;
    // vector<int> sum(n + 1) ;
    // for(int i = 1 ; i < n ; ++i) sum[i] = a[i] + sum[i - 1] ;

    int mx1 = 1 ;
    int dis1 = 0 ;
    for(int i = s - 1 ; i >= 1 ; i--){
        dis1 += a[i] ;
        if(dis1 > l) break ;
        else mx1++ ;
    }

    int mx2 = 1 ;
    int dis2 = 0 ;
    for(int i = s + 1 ; i <= n ; i++){
        dis2 += a[i - 1] ;
        if(dis2 > l) break ;
        else mx2++ ;
    }

    int mx3 = 1 ;
    int dis3 = 0 ;
    for(int i = s - 1 ; i >= 1 ; i--){
        dis3 += 2 * a[i] ;
        if(dis3 > l) break ;
        else{
            int cur = 0 ;
            for(int j = s + 1 ; j <= n ; ++j){
                cur += a[j - 1] ;
                if(cur + dis3 > l) break ;
                else mx3 = max(mx3, 1 - i + j) ;
            }
        }
    }

    int mx4 = 1 ;
    int dis4 = 0 ;
    for(int i = s + 1 ; i <= n ; ++i){
        dis4 += 2 * a[i - 1] ;
        if(dis4 > l) break ;
        else{
            int cur = 0 ;
            for(int j = s - 1 ; j >= 1 ; j--){
                cur += a[j] ;
                if(cur + dis4 > l) break ;
                else mx4 = max(mx4, i - j + 1) ;
            }
        }
    } 

    int ans = max(max(mx1, mx2), max(mx3, mx4)) ;
    cout << ans ;
    return 0;
}
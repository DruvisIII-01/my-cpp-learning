#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    vector <int> f(n + 1) ;
    //f[i] 表示以 a[i] 结尾的递减子序列的长度
    //g[i] 表示以 a[i] 结尾的最长递减子序列的取法数
    vector <int> g(n + 1) ;
    for(int i = 1 ; i <= n ; i++){
        f[i] = 1  ;
        for(int j = 1 ; j < i ; j++){
            if(a[j] > a[i]) f[i] = max(f[j] + 1, f[i]) ;
        }
    }
    
    int mx = -1, mx_cnt = 0 ;
    for(int i = 1 ; i <= n ; i++){
        mx = max(mx, f[i]) ;
    }
    cout << mx << ' ' ;
    
    for(int i = 1 ; i <= n ; i++){
        g[i] = (f[i] == 1) ;
        for(int j = 1 ; j < i ; j++){
            if(f[j] == f[i] - 1 && a[j] > a[i]) g[i] += g[j] ;
            else if(f[j] == f[i] && a[j] == a[i]) g[j] = 0 ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(mx == f[i]) mx_cnt += g[i] ;
    }
    cout << mx_cnt << endl ;
    return 0;
 }
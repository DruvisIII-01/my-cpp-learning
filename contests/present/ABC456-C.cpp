#include <bits/stdc++.h>
using namespace std ;

//#define int long long

const double P = 1.0 / (6.0 * 6.0 * 6.0) ;

signed main() {
    int a[12][12] = {} ;
    int cnt[12][12] = {} ;
    for(int t = 1 ; t <= 3 ; t++){
        for(int i = 1 ; i <= 6 ; i++){
            cin >> a[t][i] ;
            cnt[t][a[t][i]]++ ;
        }
    }
    int p1 = cnt[1][4] * cnt[2][5] * cnt[3][6], 
    p2 = cnt[1][4] * cnt[2][6] * cnt[3][5],
    p3 = cnt[1][5] * cnt[2][6] * cnt[3][4],
    p4 = cnt[1][5] * cnt[2][4] * cnt[3][6],
    p5 = cnt[1][6] * cnt[2][4] * cnt[3][5],
    p6 = cnt[1][6] * cnt[2][5] * cnt[3][4] ;
    double ans = P * (p1 + p2 + p3 + p4 + p5 + p6) ;
    printf("%.8lf", ans) ;
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 20 ;
int n ;
double x[MAXN], y[MAXN] ;
 
double dp[MAXN][(1 << MAXN)] ;
//状态第2维，当前所在节点第1维

//#define int long long

const double inff = 1.0 + 1e9 ;

double dis(int i, int j) {return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) ;}

signed main() {
    cin >> n ;
    for(int t = 1 ; t <= n ; t++) cin >> x[t] >> y[t] ;
    //开始一共 (n + 1) 个 1 = (1 << (n + 1)) - 1，表示所有奶酪都没取到
    int start = (1 << (n + 1)) - 1 ; 
    //printf("start = %d\n", start) ;
    //31 = (1 << 5) - 1 = 1 1 1 1 1
    //1 1 1 1 0 = 30 = 0
    //1 1 1 0 0 = 28 = 1.414
    for(int i = 0 ; i <= n ; i++){
        for(int t = start ; t >= 0 ; t -= 1){
            dp[i][t] = inff ;
        }
    }dp[0][start - 1] = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        dp[i][(start - 1) ^ (1 << i)] = dis(i, 0) ;
    }for(int t = start - 1 ; t >= 0 ; t -= 1){
        for(int i = 0 ; i <= n ; i++){
            if(t & (1 << i)) continue ;
            for(int j = 0 ; j <= n ; j++){
                if(!(t & (1 << j))) {
                    //cout << "succ" << endl ;
                    dp[i][t] = min(dp[i][t], dp[j][t ^ (1 << i)] + dis(i, j)) ;
                }
            }
        }
    }double mi = inff ;
    // for(int i = 0 ; i <= n ; i++){
    //     for(int t = 0 ; t <= (1 << (n + 1)) - 1 ; t++){
    //         printf("dp[%d][%d]=%lf\n", i, t, dp[i][t]) ;
    //     }cout << endl ; 
    // }cout << endl ; 
    for(int i = 1 ; i <= n ; i++) mi = min(mi, dp[i][0]) ;
    printf("%.2lf", mi) ;
    return 0;
}
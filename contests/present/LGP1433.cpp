#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 25 ;
int n ;
double x[MAXN], y[MAXN] ;
 
double dp[MAXN][(1 << MAXN) - 1] ;
//状态第2维，当前所在节点第1维

//#define int long long

double dis(int i, int j) {
    return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) ;
}

signed main() {
    cin >> n ;
    for(int t = 1 ; t <= n ; t++) cin >> x[t] >> y[t] ;
    
    return 0;
}
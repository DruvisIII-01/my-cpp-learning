#include <bits/stdc++.h>
using namespace std ;

//#define int long long

typedef struct book{
    int h ;
    int w ;
}bk ;

const int MAXN = 2222 ;
const int MAXK = 2222 ;

int dp[MAXN][MAXK] ;

bool bk_cmp (bk ss1, bk ss2){
    return ss1.h < ss2.h ;
}

signed main() {
    int n, k ; cin >> n >> k ;
    memset(dp, 127, sizeof(dp)) ;
    vector <bk> s(n + 1) ;
    for(int t = 1 ; t <= n ; t++){
        int h0, w0 ; cin >> h0 >> w0 ;
        s[t].h = h0 ; s[t].w = w0 ; 
    }
    sort(s.begin() + 1, s.begin() + n + 1, bk_cmp) ;
    for(int i = 1 ; i <= n ; i++) dp[i][1] = 0 ;
    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j < i ; j++){
            for(int l = 2 ; l <= min(i, n - k) ; l++){
                dp[i][l] = min(dp[i][l], dp[j][l - 1] + abs(s[j].w - s[i].w)) ;
            }
        }
    }
    int m1 = 1e9 ;
    for(int i = n - k ; i <= n ; i++) m1 = min(dp[i][n - k], m1) ;
    cout << m1 ;
    return 0;
}
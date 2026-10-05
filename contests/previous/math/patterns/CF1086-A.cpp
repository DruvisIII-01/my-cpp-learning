#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 224 ;

int a[MAXN][MAXN] ;
int cnt[MAXN*MAXN] ;

void solve(){
    int n ;cin >> n ;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++){
            cin >> a[i][j] ;
            cnt[a[i][j]]++ ;
        }
    }int mx = -1 ;
    for(int i = 1 ; i <= n*n ; i++) mx = max(mx, cnt[i]) ;
    if(mx <= n*(n-1)) cout << "YES" ;
    else cout << "NO" ;

    for(int i = 1 ; i <= n*n ; i++){
        cnt[i] = 0 ;
    }
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】Bingo Candies
 * 题目链接：https://codeforces.com/problemset/problem/2208/A
 * 标签：难度 800 | constructive algorithms, math
 *
 * 关键思路：统计每种颜色出现次数 c，若存在 c > n(n-1) 则不满足抽屉原理，输出 NO；否则 YES。
 * ###################################################################### */

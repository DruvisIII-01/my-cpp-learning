#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n + 1) ;
    vector<int> hsh(n + 1, 0) ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        hsh[a[i]]++ ;
    }//bool find = false ;
    int ans = -1 ; 
    for(int i = 1 ; i <= n ; i++){
        if(hsh[i] == 1){
            ans = i ;
            break ;
        }
    }if(ans == -1) cout << ans ;
    else{
        for(int i = 1 ; i <= n ; i++){
            if(a[i] == ans){
                cout << i ;
                break ;
            }
        }
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
 * 【题面与关键思路】Unique Bid Auction
 * 题目链接：https://codeforces.com/problemset/problem/1454/B
 * 标签：难度 800 | implementation
 *
 * 关键思路：桶计数找出"恰好出现一次"的最小值，输出它的下标。
 * ###################################################################### */

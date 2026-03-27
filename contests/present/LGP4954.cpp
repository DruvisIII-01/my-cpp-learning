#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    vector <int> pre(n + 1) ;
    vector <int> w(n + 1) ;
    vector <int> dp(n + 1) ;
    deque <int> dq ;
    for(int i = n ; i >= 1 ; i--) cin >> a[i] ;
    for(int i = 1 ; i <= n ; i++) pre[i] = pre[i - 1] + a[i] ;

    //brute force linear dp
    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = 0 ; j < i ; j++){
    //         //find the first j, w[j] + pre[j] <= pre[i] 
    //         if(pre[i] - pre[j] >= w[j]){
    //             dp[i] = dp[j] + 1 ;
    //             w[i] = pre[i] - pre[j] ;
    //             break ;
    //         }
    //     }
    // }

    int pos = 0 ;
    for(int i = 1 ; i <= n ; i++){
        //find the first j, w[j] + pre[j] <= pre[i]
        //dq increases with pre + w(last width) 
        //and decreases with index(reverse)
        while(!dq.empty() && pre[dq.front()] + w[dq.front()] <= pre[i]){
            pos = dq.front() ;
            dq.pop_front() ;
        }
        dp[i] = dp[pos] + 1 ;
        w[i] = pre[i] - pre[pos] ;
        while(!dq.empty() && pre[dq.back()] + w[dq.back()] > pre[i] + w[i]) 
        dq.pop_back() ;
        dq.push_back(i) ;
    }
    cout << dp[n] ;
    //a[i] reverse 
    //dp[i], 1 to i, max floors
    //w[i], min width of the floor end with a[i]
    return 0;
}
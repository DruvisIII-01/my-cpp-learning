#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ;
    vector <int> a(n + 1) ;
    vector <int> pre(n + 1) ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        pre[i] = pre[i - 1] + a[i] ;
    }
    // vector <int> suf(n + 1) ;
    // suf[n] = a[n] ;
    // for(int i = n - 1 ; i >= 1 ; i--){
    //     suf[i] = suf[i + 1] + a[i] ;
    // }
    int check = pre[n] / 2 ;
    int end = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(pre[i] > check) {
            end = i - 1 ;
            break ;
        }
    }
    int ans = 0 ;
    int left_sum = 0, right_sum = 0 ;
    int right = n ;
    for(int left = 1 ; left <= end ; left++){
        left_sum += a[left] ;
        while(right > left && left_sum > right_sum) {
            right_sum += a[right] ;
            right-- ;
        }
        //printf("%d %d %d %d\n", left, right, left_sum, right_sum) ;
        if(right_sum == left_sum) ans = n - right + left ; 
    }
    cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
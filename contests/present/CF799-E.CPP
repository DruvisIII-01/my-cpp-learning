#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, target ; cin >> n >> target ;
    vector <int> a(n + 1) ;
    int sum = 0 ;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        sum += a[i] ;
    }if(sum < target) {
        cout << "-1" ;
        return ;
    }else if(sum == target){
        cout << '0' ;
        return ;
    }int right = 1 ;
    int mx = -1 ;
    int cur_sum = 0 ;
    for(int left = 1 ; left <= n ; ++left){
        if(right < left) right = left ; 
        while(right <= n && cur_sum <= target){
            cur_sum += a[right] ;
            if(cur_sum > target){
                cur_sum -= a[right] ;
                break ;
            }
            right++ ;
        }
        if(cur_sum == target) mx = max(mx, right - left) ;
        cur_sum -= a[left] ;
    }cout << n - mx ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
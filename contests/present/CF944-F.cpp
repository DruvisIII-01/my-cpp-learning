#include <bits/stdc++.h>

using namespace std ;

#define int long long

int SQ(int N) {
    if(!N) return 0 ;
    int left = 0, right = (int)sqrt(N) + 1e4 ;
    while(left + 1 != right){
        int mid = (left + right) >> 1 ;
        if (mid * mid >= N) right = mid ;
        else left = mid ;
    }
    return right ;
}

void solve(){
    int ans = 0 ;
    int r = -1 ; cin >> r ;
    for(int k = 1 ; k <= r ; ++k){
        int L = SQ(r * r - k * k) ;
        int R = SQ(r * r + r * 2 + 1 - k * k) ;
        ans += R - L ;
    }
    cout << ans * 4 ;
}

signed main(){
    int T ; cin >> T ;
    while(T--){
        solve() ;
        cout << endl ;
    }
}
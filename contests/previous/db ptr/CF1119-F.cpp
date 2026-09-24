#include <bits/stdc++.h>
using namespace std ;

#define int long long

int cntInv(vector<int>&a){
    int n = a.size() - 1 ;
    int cnt1 = 0 ;
    vector<int>dp(n + 1) ;
    for(int t = 1 ; t <= n ; ++t){
        if(!a[t]) dp[t] = dp[t - 1] + cnt1 ;
        else {
            cnt1++ ;
            dp[t] = dp[t - 1] ;
        }
    }
    return dp[n] ;
}

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    string s ; cin >> s ;

    int one_sum = 0 ;
    int zero_sum = 0 ;
    for(int t = 1 ; t <= n ; ++t){
        one_sum += a[t] ;
        zero_sum += !a[t] ;
    }

    int base = cntInv(a) ;
    cout << base << ' ' ;
    // cout << '\n' ;

    deque<int> dq;
    for(int i = 1 ; i <= n ; ++i) dq.push_back(a[i]) ;
    for(char ch : s){
        // for(int x : dq) cout << x << ' ' ;
        // cout << '\n' ;

        while(!dq.empty() && dq.front() == 0){
            dq.pop_front() ;
            zero_sum-- ;
        }while(!dq.empty() && dq.back() == 1){
            dq.pop_back() ;
            one_sum-- ;
        }if(dq.empty()){
            cout << "0 " ;
            continue ;
        }

        if(ch == '1'){
            dq.pop_front() ;
            one_sum-- ;
            base -= zero_sum ;
        }else{
            dq.pop_back() ;
            zero_sum-- ;
            base -= one_sum ;
        }cout << base << ' ' ;
        // cout << '\n' ;
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
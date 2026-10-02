#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    string s ; cin >> s ; s = '*' + s ;
    
    int cnt0 = 0 ;
    for(int i = 1 ; i <= n ; ++i) cnt0 += (s[i] == '0') ;

    //special judge: initial not desc
    int perfect = true ;
    for(int i = 2 ; i <= n ; ++i){
        if(s[i] < s[i - 1]) {
            perfect = false ;
            break ;
        }
    }if(perfect){
        cout << 0 ;
        return ;
    }
    //special judge: first 1
    if(s[1] == '1') {
        cout << cnt0 ;
        return ;
    }
    //special jugde: all zero
    int ans = n - cnt0 ;//把所有1都变成0
    
    //计算后缀0的个数
    vector<int> aft(n + 2) ;
    aft[n] = (s[n] == '0') ;
    for(int i = n - 1 ; i > 0 ; i--)
    aft[i] = aft[i + 1] + (s[i] == '0') ;

    //计算1第一次出现的位置
    int fir = 2 ;
    for(int i = 2 ; i <= n ; ++i){
        if(s[fir] == '1'){
            fir = i ;
            break ;
        }
    }//枚举从fir到n每一个位置
    int cnt1 = 0 ;
    for(int i = fir ; i <= n ; ++i){
        if(s[i] == '1') {
            ans = min(ans, cnt1 + aft[i + 1]) ;
            cnt1++ ;
        }else ans = min(ans, cnt1 + 1 + aft[i + 1]) ;
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
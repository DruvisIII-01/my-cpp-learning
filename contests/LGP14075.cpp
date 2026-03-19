#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int n ; cin >> n ;
    string s ; cin >> s ;
    vector <int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;

    vector <int> dp(n) ;
    //dp[i] 表示到第 i + 1 个字符为止，最优划分带来的价值
    dp[0] = a[1] ;
    for(int i = 1 ; i < n ; i++){
        set <char> st ;
        //st.insert(s[i]) ;
        for(int j = i ; j >= 0 ;j--){
            if(!st.count(s[j])){
                st.insert(s[j]) ;
                if(j > 0) {
                    dp[i] = max(dp[i], dp[j - 1] + a[i - j + 1]) ;
                }else {
                    dp[i] = max(dp[i], a[i + 1]) ;
                }
            }else{
                break ;
            }
        }st.clear() ;
    }
    cout << dp[n - 1] ;
    return 0;
}
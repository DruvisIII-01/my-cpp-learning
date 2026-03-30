#include <bits/stdc++.h>
using namespace std ;

#define int long long

static int x, t ;

int digit[300] ;
int dp[200][200][2][2] ;

int dfs(int now, int len, bool is_free, bool is_num){
    //cout << "开始递归 " ;
    if(!len) {
        //注意t == 0的特殊情况
        if(!is_num) return now + (t == 0) ; else return now ; 
    }
    int ans = 0, cur = digit[len], start = (is_num == 0);
    //注意!is_num时，要么这一位依旧是前导零，要么一定要从1到9选一位填充
    if(!is_num){
        if(dp[now][len - 1][1][0] != -1) ans += dp[now][len - 1][1][0] ;
        else{
            int tmp1 = dfs(now, len - 1, true, false) ;
            ans += tmp1 ;
            dp[now][len - 1][1][0] = tmp1 ;
        }
    } 
    if(!is_free){
        for(int i = start ; i < cur ; i++) {
            if(dp[now + (i == t)][len - 1][1][1] != -1) ans += dp[now + (i == t)][len - 1][1][1] ;
            else {
                int tmp2 = dfs(now + (i == t), len - 1, true, true) ;
                ans += tmp2 ;
                dp[now + (i == t)][len - 1][1][1] = tmp2 ;
            }
        }
        //ans += dfs(now + (cur == t), len - 1, false, true) ;
        if(dp[now + (cur == t)][len - 1][0][1] != -1) ans += dp[now + (cur == t)][len - 1][0][1] ;
        else {
            int tmp3 = dfs(now + (cur == t), len - 1, false, true) ;
            ans += tmp3 ;
            dp[now + (cur == t)][len - 1][0][1] = tmp3 ;
        }
    }else for(int i = start ; i <= 9 ; i++) {
        // ans += dfs(now + (i == t), len - 1, true, true) ;
        if(dp[now + (i == t)][len - 1][1][1] != -1) ans += dp[now + (i == t)][len - 1][1][1] ;
        else{
            int tmp4 = dfs(now + (i == t), len - 1, true, true) ;
            ans += tmp4 ;
            dp[now + (i == t)][len - 1][1][1] = tmp4 ;
        }
    }
    return ans ;
}

//现在求[0, x]之中，一共有多少个t
int Count0(){
    //特殊情况要特判
    if(x < 0) return 0 ;
    if(x == 0) return (t == 0) ;
    int tmp = x, len = 0 ;
    while(tmp > 0){
        tmp /= 10 ;
        len++ ;
    }tmp = x ;
    memset(digit, 0, sizeof(digit)) ;
    memset(dp, -1, sizeof(dp)) ;
    for(int i = 1 ; i <= len ; i++){
        digit[i] = tmp % 10 ;
        tmp /= 10 ;
    }return dfs(0, len, false, false) ;
}

signed main() {
    int a, b ; cin >> a >> b ;
    for(int i = 0 ; i <= 9 ; i++) {
        // cout << Count0(b, i) - Count0(a - 1, i) << ' ' ;
        x = b, t = i ;
        int d1 = Count0() ;
        x = a - 1, t = i ;
        int d2 = Count0() ;
        cout << d1 - d2 << ' ' ;
    } 
    return 0;
}

#include <bits/stdc++.h>
using namespace std ;

#define int long long

int digit[30] ;
int dp[300][300][2][2] ;

int dfs(int sum, int len, bool is_free, bool is_num){
    if(!len){
        if(!is_num) return 0 ;
        else return sum ;
    }int cur = digit[len], ans = 0, start = (is_num == 0) ;
    if(!is_num){
        if(dp[sum][len - 1][1][0] != -1) ans += dp[sum][len - 1][1][0] ;
        else {
            int tmp1 = dfs(sum, len - 1, 1, 0) ;
            ans += tmp1 ;
            dp[sum][len - 1][1][0] = tmp1 ;
        }
    } //ans += dfs(sum, len - 1, 1, 0) ;
    if(!is_free){
        for(int i = start ; i < cur ; i++){
            if(dp[sum + i][len - 1][1][1] != -1) ans += dp[sum + i][len - 1][1][1] ;
            else {
                int tmp2 = dfs(sum + i, len - 1, 1, 1) ;
                ans += tmp2 ;
                dp[sum + i][len - 1][1][1] = tmp2 ;
            }
        }// ans += dfs(sum + i, len - 1, 1, 1) ;
        if(dp[sum + cur][len - 1][0][1] != -1) ans += dp[sum + cur][len - 1][0][1] ;
        else {
            int tmp3 = dfs(sum + cur, len - 1, 0, 1) ;
            ans += tmp3 ;
            dp[sum + cur][len - 1][0][1] = tmp3 ;
        }
        //ans += dfs(sum + cur, len - 1, 0, 1) ;
    }else{
        for(int i = start ; i <= 9 ; i++){
            if(dp[sum + i][len - 1][1][1] != -1) ans += dp[sum + i][len - 1][1][1] ;
            else {
                int tmp4 = dfs(sum + i, len - 1, 1, 1) ;
                ans += tmp4 ;
                dp[sum + i][len - 1][1][1] = tmp4 ;
            }
        } //ans += dfs(sum + i, len - 1, 1, 1) ;
    }//cout << "本次递归得到答案：" << ans << endl ;
    return ans ;
}

int Cnt(int x){
    if(x <= 0) return 0 ;
    int tmp = x, len = 0 ;
    while(tmp > 0){
        len++ ;
        tmp /= 10 ;
    }//cout << len << endl ;
    tmp = x ;
    memset(digit, 0, sizeof(digit)) ;
    memset(dp, -1, sizeof(dp)) ;
    for(int i = 1 ; i <= len ; i++) {
        digit[i] = tmp % 10 ;
        //cout << digit[i] << ' ' ;
        tmp /= 10 ;
    }//cout << endl ;
    return dfs(0, len, 0, 0) ;
} 

signed main() {
    int n ; cin >> n ;
    cout << Cnt(n) ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】P1836 数页码
 * 题目链接：https://www.luogu.com.cn/problem/P1836
 * 标签：难度 洛谷 普及- | 数位统计, 数学, 按位贡献
 *
 * 关键思路：求 1..n 所有页码的数字之和。记忆化 dfs(sum, len, is_free, is_num) 直接累加数位和；也可按位贡献 O(log n) 数学计算。
 * ###################################################################### */

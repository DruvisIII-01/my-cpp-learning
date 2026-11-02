#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int m, n ; 
    while(cin >> m >> n){
        if(!m && !n) break ;
        vector<vector<int>> mp(m + 1, vector<int>(n + 1)) ;
        for(int i = 1 ; i <= m ; ++i){
            string row ; cin >> row ; row = ' ' + row ;
            for(int j = 1 ; j <= n ; ++j){
                if(row[j] == '*') mp[i][j] = 0 ;
                else if(row[j] == '.') mp[i][j] = 1 ;
            }
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1)) ;
        for(int j = 1 ; j <= n ; ++j){
            dp[1][j] = mp[1][j] ;
            for(int i = 1 ; i <= m ; ++i){
                if(!mp[i][j]) dp[i][j] = 0 ;
                else dp[i][j] = dp[i - 1][j] + 1 ;
            }
        }

        int mx = -1 ;
        for(int i = 1 ; i <= m ; ++i){
            vector<int> right(n + 1) ;
            stack<int> stk1 ;
            for(int t = n ; t >= 1 ; t--){
                if(stk1.empty()) {
                    stk1.push(t) ;
                    right[t] = n + 1 ; 
                }else{
                    bool find = false ;
                    while(!stk1.empty()){
                        int tp = stk1.top() ;
                        if(dp[i][tp] >= dp[i][t]) stk1.pop() ;
                        else{
                            find = true ;
                            stk1.push(t) ;
                            right[t] = tp ;
                            break ;
                        }
                    }if(!find){
                        stk1.push(t) ;
                        right[t] = n + 1 ;
                    }
                }
            }
            
            vector<int> left(n + 1) ;
            stack<int> stk2 ; 
            for(int t = 1 ; t <= n ; ++t){
                if(stk2.empty()) {
                    stk2.push(t) ;
                    left[t] = 0 ;
                }else{
                    bool find = false ;
                    while(!stk2.empty()){
                        int tp = stk2.top() ;
                        if(dp[i][tp] >= dp[i][t]) stk2.pop() ;
                        else{
                            find = true ;
                            stk2.push(t) ;
                            left[t] = tp ;
                            break ;
                        }
                    }if(!find){
                        stk2.push(t) ;
                        left[t] = 0 ;
                    }
                }
            }
            for(int j = 1 ; j <= n ; ++j)
            mx = max(mx, (right[j] - left[j] - 1) * dp[i][j]) ;
        }cout << mx << endl ;
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】DSHW03-B 最大矩形/柱状图连续段
 * 来源：学院课程作业（非竞赛题，无官方难度/标签）
 * 标签：难度 课程作业 | dp, 网格
 *
 * 关键思路：逐列做"向上连续可用格数"的 DP：`dp[i][j] = dp[i-1][j] + 1`（遇到障碍清零），再在每行统计连续区间。
 * ################################################################## */

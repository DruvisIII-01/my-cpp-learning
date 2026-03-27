#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
bool vis[1005][1005];

signed main() {
    int n, m, x, y; 
    cin >> n >> m >> x >> y;
    
    // 标记马的控制点
    vis[x][y] = true;
    for(int i = 0; i < 8; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx >= 0 && tx <= n && ty >= 0 && ty <= m) 
            vis[tx][ty] = true;
    }
    
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    
    // 初始化起点
    if(!vis[0][0]) dp[0][0] = 1;
    
    // 初始化第一列
    for(int i = 1; i <= n; i++) {
        if(!vis[i][0]) 
            dp[i][0] = dp[i-1][0];
    }
    
    // 初始化第一行
    for(int j = 1; j <= m; j++) {
        if(!vis[0][j]) 
            dp[0][j] = dp[0][j-1];
    }
    
    // 动态规划
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(vis[i][j]) 
                dp[i][j] = 0;
            else 
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    cout << dp[n][m] << endl;
    return 0;
}
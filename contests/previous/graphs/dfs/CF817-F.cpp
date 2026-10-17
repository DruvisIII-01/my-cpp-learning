#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, m ; cin >> n >> m ;

    vector<vector<int>> a(n + 1, vector<int>(m + 1)) ;
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, -1)) ;
    vector<int> vi(4) ; vi = {0, 1, 0, 1} ;
    vector<int> vj(4) ; vj = {0, 0, 1, 1} ;
    vector<int> lx ; vector<int> ly ;
    vector<vector<int>> vx(4, vector<int>(12)) ; vx = {
        {-2, -2, -2, -1, 0, 1, 1, 1, 1, 0, -1, -1}, //dir == 0
        {-1, -1, -1, -1, 0, 1, 2, 2, 2, 1, 1, 0}, //dir == 1 
        {-2, -2, -2, -1, -1, 0, 1, 1, 1, 1, 0, -1}, //dir == 2
        {-1, -1, -1, -1, 0, 1, 1, 2, 2, 2, 1, 0} //dir == 3
    } ;
    vector<vector<int>> vy(4, vector<int>(12)) ; vy = {
        {-1, 0, 1, 1, 1, 1, 0, -1, -2, -2, -2, -1}, //dir == 0
        {-2, -1, 0, 1, 1, 1, 1, 0, -1, -1, -2, -2}, //dir == 1 
        {-1, 0, 1, 1, 2, 2, 2, 1, 0, -1, -1, -1}, //dir == 2
        {-1, 0, 1, 2, 2, 2, 1, 1, 0, -1, -1, -1} //dir == 3
    } ;
    //dir表示田字格空白的位置 
    //dir = 0, left-up
    //dir = 1, left-down
    //dir = 2, right-up
    //dir = 3, right-down

    for(int t = 1 ; t <= n ; ++t){
        string s ; cin >> s ; s = ' ' + s ;
        for(int i = 1 ; i <= m ; ++i)
        if(s[i] == '*') a[t][i] = 1 ;
    }

    for(int i = 1 ; i < n ; ++i){
        for(int j = 1 ; j < m ; ++j){
            //(i, j)为每个田字格的左上角
            int wi = i, wj = j, wcnt = 0, dir = 0;
            for(int t = 0 ; t < 4 ; ++t){
                int di = i + vi[t], dj = j + vj[t] ;
                if(!a[di][dj] || vis[di][dj] != -1){
                    wcnt++ ;
                    dir = t ;
                    wi = di ;
                    wj = dj ;
                }
            }
            if(1 == wcnt){
                int bi = (i << 1) + 1 - wi, bj = (j << 1) + 1 - wj ;
                lx.push_back(bi) ; ly.push_back(bj) ;
                for(int t = 0 ; t < 4 ; ++t){
                    int di = i + vi[t], dj = j + vj[t] ;
                    if(di != wi || dj != wj) vis[di][dj] = dir ;
                }
            }
        }
    }

    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(a[i][j] && vis[i][j] == -1){
                cout << "NO" ;
                return ;
            }
        }
    }

    int sz = lx.size() ;
    for(int t = 0 ; t < sz ; ++t){
        int rx = lx[t], ry = ly[t], dir = vis[rx][ry] ;
        for(int k = 0 ; k < 12 ; ++k){
            int dx = rx + vx[dir][k], dy = ry + vy[dir][k] ;
            if(dx < 1 || dx > n || dy < 1 || dy > m) continue ;
            if(a[dx][dy]){
                cout << "NO" ;
                return ;
            }
        }
    }cout << "YES" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
/* ######################################################################
 * 【题面与关键思路】L-shapes
 * 题目链接：https://codeforces.com/problemset/problem/1722/F
 * 标签：难度 1700 | dfs and similar, implementation
 *
 * 关键思路：2×2 的"田字格"里必须恰好有 3 个 *（组成 L 形），且 12 邻域内不能再有其它 *。逐格枚举田字格、记录唯一空位确定朝向，再用 12 方向邻域检查是否与其他 L 形冲突。也可以用 DFS 找连通块后判形状。
 * ###################################################################### */

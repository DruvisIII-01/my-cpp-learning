#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int LIMIT = 20 ;

struct seg{
    int id ; 
    int l, r ; 
} ; 
auto cmp_seg = [](const auto& S1, const auto& S2){
    return S1.l < S2.l ; 
} ;

signed main() {
    int n, m ; cin >> n >> m ;
    vector<struct seg> p(n + 1) ;
    vector<struct seg> a(1) ; 
    vector<int> pos(n + 1) ;
    for(int t = 1 ; t <= n ; ++t){
        int x, y ; cin >> x >> y ; if(y < x) y += m ; 
        p[t] = {t, x, y} ;
    }sort(p.begin() + 1, p.end(), cmp_seg) ;
    for(int t = 1 ; t <= n ; ++t) pos[p[t].id] = t ; 
    for(int t = 1 ; t <= n ; ++t) a.push_back({p[t].id, p[t].l, p[t].r}) ;
    for(int t = 1 ; t <= n ; ++t) a.push_back({p[t].id + n, p[t].l + m, p[t].r + m}) ;
    // for(int t = 1 ; t <= 2 * n ; ++t) cout << a[t].id << endl << a[t].l << ' ' << a[t].r << endl ; cout << endl ; 

    vector<vector<int>> st(2 * n + 1, vector<int>(LIMIT)) ;
    int right = 1 ;
    for(int left = 1 ; left <= 2 * n ; ++left){
        while(right <= 2 * n && a[left].r >= a[right].l) right++ ;
        st[left][0] = right - 1 ;
        //cout << st[a[left].id][0] << ' ' ;
    }//cout << endl ; 
    for(int d = 1 ; d < LIMIT ; ++d){
        for(int t = 1 ; t <= 2 * n ; ++t){
            int mid = st[t][d - 1] ;
            st[t][d] = st[mid][d - 1] ;
        }
    }
    //for(int t = 1 ; t <= n * 2 ; ++t) cout << st[t][1] << ' ' ; cout << endl ; 

    vector<int> Ans(n + 1) ; 
    for(int t = 1 ; t <= n ; ++t){
        int cur = pos[t], ans = 0 ; 
        for(int D = LIMIT - 1 ; D >= 0 ; D--){
            if(st[cur][D] < pos[t] + n){
                cur = st[cur][D] ;
                ans += (1 << D) ;
            }
        }Ans[t] = ans + 1 ;
    }
    for(int t = 1 ; t <= n ; ++t) cout << Ans[t] << ' ' ;
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】P4155 [SCOI2015] 国旗计划
 * 题目链接：https://www.luogu.com.cn/problem/P4155
 * 标签：难度 洛谷 提高+/省选- | 倍增, 贪心, ST 表
 *
 * 关键思路：把区间复制一份处理环形，按左端点排序后用 ST 表实现"跳 2^k 个区间"，每个区间倍增求出覆盖整圈所需的最少段数。
 * ################################################################## */

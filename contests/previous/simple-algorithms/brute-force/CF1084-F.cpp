#include <bits/stdc++.h>
using namespace std ;

#define int long long
struct p { int x, y ;};
auto cmp_y = [](const auto& p1, const auto& p2){
    return p1.y > p2.y ;
} ;
auto cmp_x = [](const auto& p1, const auto& p2){
    return p1.x > p2.x ;
} ;

void solve(){
    int n, m ; cin >> n >> m ; 
    vector<p> a(n + 1) ;
    int mx_y = -1 ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t].x >> a[t].y ;
        a[t].y++ ;
        mx_y = max(mx_y, a[t].y) ;
    }
    //cout << mx_y << endl ;
    sort(a.begin() + 1, a.end(), cmp_y) ;
    // for(int t = 1 ; t <= n ; ++t) cout << a[t].x << ' ' << a[t].y << endl ; 
    
    vector<int> sumSub(n + 2) ;
    vector<int> miSub(n + 2) ;
    vector<int> szSub(n + 2) ;
    priority_queue<p, vector<p>, decltype(cmp_x)> pq(cmp_x) ;
    int start = 1, pq_sz = 0, pq_sumx = 0 ; 
    for(int sz = mx_y ; sz >= 1 ; sz--){
        for(int t = start ; t <= n ; ++t){
            if(a[t].y < sz) {
                start = t ;
                break ;
            }
            else{
                pq.push(a[t]) ;
                pq_sz++ ;
                pq_sumx += a[t].x ;
                if(t == n){
                    start = n + 1 ;
                    break ;
                }
            }
        }while(pq_sz > sz){
            p tp = pq.top() ;
            pq.pop() ;
            pq_sz-- ;
            pq_sumx -= tp.x ;
        }sumSub[sz] = pq_sumx ;
        miSub[sz] = pq.top().x ;
        szSub[sz] = pq_sz ;
    }

    int MX = 0 ;
    for(int t = 1 ; t <= mx_y ; ++t) MX = max(MX, sumSub[t]) ;vector<int> sub(n + 2) ;
    for(int t = 1 ; t <= mx_y ; ++t) {
        if(szSub[t] == t) sub[t] = sumSub[t] - miSub[t] ;
        else sub[t] = sumSub[t] ;
    }vector<int> preSub(n + 2) ;
    for(int t = 1 ; t <= n + 1 ; ++t) preSub[t] = max(preSub[t - 1], sub[t]) ;
     
    //for(int t = 1 ; t <= mx_y ; ++t) cout << sumSub[t] << endl ;

    for(int TTT = 1 ; TTT <= m ; ++TTT){
        int nx, ny ; cin >> nx >> ny ;
        ny++ ;//ny = min(ny, mx_y);
        int ans1 = nx + preSub[ny] ,ans2 = MX ;
        cout << max(ans1, ans2) << ' ' ;
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

/* ##################################################################
 * 【题面与关键思路】Mooclear Reactor 2
 * 题目链接：https://codeforces.com/problemset/problem/2200/F
 * 标签：难度 1900 | brute force, data structures, greedy, implementation, sortings
 *
 * 关键思路：把点按 y 排序后从高到低扫，用优先队列维护当前层的 x；对每个后缀计算 min/sum，枚举"被删掉的点数"取最优差值。
 * ################################################################## */

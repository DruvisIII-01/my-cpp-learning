#include <bits/stdc++.h>
using namespace std ;

#define int long long
const double MxDist = (double)__LONG_LONG_MAX__ / 224 ;
struct point{
    int x, y ;
} ;
double dist(struct point p1, struct point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)) ; 
}
auto cmp_x = [](const auto& p1, const auto& p2){
    return p1.x < p2.x ; 
} ;
auto cmp_y = [](const auto& p1, const auto& p2){
    return p1.y < p2.y ;
} ;

double miDist(vector<struct point>& a){
    if(a.size() == 1) return MxDist ;
    if(a.size() == 2) return dist(a[0], a[1]) ;
    int Mid = a.size() >> 1, Mid_y = a[Mid].y ;
    vector<struct point> b1, b2 ;
    for(int t = 0 ; t < Mid ; ++t) b1.push_back(a[t]) ;
    for(int t = Mid ; t < a.size() ; ++t) b2.push_back(a[t]) ;
    double d1 = min(miDist(b1), miDist(b2)) ;

    vector<struct point> tmp ; 
    for(int t = 0 ; t < a.size() ; ++t) 
    if(abs(a[t].y - Mid_y) <= d1) tmp.push_back(a[t]) ;
    sort(tmp.begin(), tmp.end(), cmp_x) ;

    double d2 = d1 ;
    for(int t = 0 ; t < a.size() ; ++t){
        double cur = MxDist ;
        for(int i = 1 ; i <= 6 ; ++i){
            if(t + i >= a.size()) break ;
            cur = min(cur, dist(a[t], a[t + i])) ;
        }
        d2 = min(d2, cur) ;
    }return min(d1, d2) ;
}

signed main() {
    int n ; cin >> n ; 
    vector<struct point> a(n) ;
    for(int t = 0 ; t < n ; ++t) cin >> a[t].x >> a[t].y ;
    sort(a.begin(), a.end(), cmp_y) ;
    double ans = miDist(a) ; printf("%.4lf", ans) ; 
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】DSHW04-B 平面最近点对（分治）
 * 来源：数据结构课程作业（非竞赛题，无官方难度/标签）
 * 标签：课程作业 | 分治, 计算几何
 *
 * 关键思路：按 x 排序后二分，递归求左右两半的最近距离 d1；再收集 |y − mid_y| ≤ d1 的点按 x 排序，只比较相邻的常数个点更新答案（经典 O(n log n) 分治）。
 * ################################################################## */

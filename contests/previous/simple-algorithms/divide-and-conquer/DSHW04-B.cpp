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
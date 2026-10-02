#include <bits/stdc++.h>
using namespace std ;

//#define int long long
int last[224524] ;
signed main() {
    int n, q ; cin >> n >> q ; 
    vector<int> a(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;

    for(int t = 1 ; t <= q ; ++t) {
        int aq = -1 ; cin >> aq ;
        last[aq] = t ;
    }

    vector<int> ans ;
    vector<int> to_sort ;
    for(int t = 1 ; t <= n ; ++t) {
        if(!last[a[t]]) ans.push_back(a[t]) ;
        else to_sort.push_back(a[t]) ;
    }
    auto cmp = [](const int &i, const int &j){
        return last[i] < last[j] ;
    } ;
    sort(to_sort.begin(), to_sort.end(), cmp) ;
    for(int x : to_sort) ans.push_back(x) ;
    for(int x : ans) cout << x << ' ' ;
    return 0;
}
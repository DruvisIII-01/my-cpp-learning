#include <bits/stdc++.h>
using namespace std ;

//#define int long long

signed main() {
    int n, m, q ; cin >> n >> m >> q ;
    vector<int> a(n + 1) ; vector<int> b(m + 1) ;
    unordered_map<int, bool> visA ; unordered_map<int, bool> visB ;
    int sumA = 0 ; int sumB = 0 ; 
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        visA[n + a[t]] = true ;
        sumA += a[t] ;
    }
    sort(a.begin() + 1, a.end()) ;
    for(int t = 1 ; t <= m ; ++t) {
        cin >> b[t] ;
        visB[m + b[t]] = true ;
        sumB += b[t] ;
    }
    for(int t = 1 ; t <= q ; ++t){
        int x ; cin >> x ;
        vector<int> pos ;
        if(!x) pos.push_back(0) ;
        else for(int i = 1 ; i * i <= abs(x) ; ++i) if(x % i == 0) pos.push_back(i) ;     
        bool is_ok = false ;
        for(int i : pos){
            if(i){
                if(visA[sumA - i + n] && visB[sumB - x / i + m]) is_ok = true ;
                if(visA[sumA + i + n] && visB[sumB + x / i + m]) is_ok = true ;
                if(visA[sumA - x / i + n] && visB[sumB - i + m]) is_ok = true ;
                if(visA[sumA + x / i + n] && visB[sumB + i + m]) is_ok = true ;
            }if(is_ok) break ;
        }if(is_ok) cout << "YES" << endl ;
        else cout << "NO" << endl ;
    }
    return 0;
}
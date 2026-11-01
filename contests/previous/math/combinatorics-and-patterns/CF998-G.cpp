#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define pii pair<int, int>
auto cmp_pii = [](const auto& p1, const auto& p2){
    return min(p1.first, p1.second) < min(p2.first, p2.second) ;
} ;

void solve(){
    int n ; cin >> n ; //cout << "11\n" ;
    vector<int> a(n + 1) ;
    vector<int> b(n + 1) ; //cout << "13\n" ;
    vector<pii> p(n + 1) ; //cout << "14\n" ;
    for(int t = 1 ; t <= n ; ++t) cin >> a[t] ;
    //cout << "15\n" ; 
    for(int t = 1 ; t <= n ; ++t) cin >> b[t] ;
    //cout << t << endl ;
    //cout << "16\n" ;
    for(int t = 1 ; t <= n ; ++t){
        p[t].first = a[t] ;
        p[t].second = b[t] ;
    }//cout << "20\n" ;
    sort(p.begin() + 1, p.end(), cmp_pii) ;
    //cout << "22\n" ;
    
    bool impossible = false ;
    for(int t = 2 ; t <= n ; ++t){
        int mx2 = max(p[t].first, p[t].second) ;
        int mx1 = max(p[t - 1].first, p[t - 1].second) ;
        if(mx1 > mx2){
            impossible = true ;
            break ;
        }
    }if(impossible){
        cout << "NO" ;
        return ;
    }//cout << "29\n" ;

    vector<bool> depend(n + 1) ;
    for(int t = 2 ; t <= n ; ++t){
        int mi2 = min(p[t].first, p[t].second) ;
        int mx1 = max(p[t - 1].first, p[t - 1].second) ;
        if(mx1 > mi2) depend[t] = true ;
    }//cout << "48\n" ;

    vector<vector<int>> segs ; 
    vector<int> seg ;
    for(int t = 1 ; t <= n ; ++t){
        if(depend[t]) {
            seg.push_back(t) ;
            if(n == t) segs.push_back(seg) ;
        }
        else{
            if(!seg.empty()) segs.push_back(seg) ;
            seg.clear() ;
            if(t < n && depend[t + 1]) seg.push_back(t) ;
        }
    }//cout << "60\n" ;

    vector<bool> free(n + 1, true) ;
    for(int t = 0 ; t < segs.size() ; ++t){
        for(int i = 0 ; i < segs[t].size() ; ++i)
        free[segs[t][i]] = false ;
    }int freeExist = false ;
    for(int t = 1 ; t <= n ; ++t) {
        if(free[t]) {
            freeExist = true ;
            break ;
        }
    }if(freeExist){
        cout << "YES" ;
        return ;
    }//cout << "75\n" ;

    int free_flip = 0, odd_flip = 0 ;
    for(int t = 0 ; t < segs.size() ; ++t){
        int up = 0, down = 0 ;
        for(int i = 0 ; i < segs[t].size() ; ++i){
            if(p[segs[t][i]].first > p[segs[t][i]].second) up++ ;
            else down++ ;
        }
        odd_flip += ((down & 1) && (up & 1)) ;
        free_flip += ((down & 1) ^ (up & 1)) ;
    }
    if(!(odd_flip & 1) || ((odd_flip & 1) && (free_flip > 0))) cout << "YES" ;
    else cout << "NO" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct interval{
    int fir ;
    int sec ;
} ;
auto cmp = [](interval& i1, interval& i2){
    return i1.fir < i2.fir ;
} ;

void solve(){
    int n ; cin >> n ;
    vector <int> b(n + 1) ;
    for(int i = 1 ; i <= n ; ++i) cin >> b[i] ;

    vector<interval> itv ; 
    
    for(int i = 1 ; i <= n ; ++i) {
        int x = b[i] ;
        if(x == -1) continue ;
        if(x + i > n && i - x < 1) {
            cout << "-1" ;
            return ;
        }else if(x + i <= n && i - x >= 1){
            // one.insert(x + i) ;
            // one.insert(i - x) ;
            interval ITV ;
            ITV.fir = i - x + 1 ;
            ITV.sec = i + x - 1 ;
            itv.push_back(ITV) ; 
        }else if(x + i <= n && i - x < 1){
            //one.insert(x + i) ;
            interval ITV ; 
            ITV.fir = 1 ; 
            ITV.sec = i + x - 1 ;
            itv.push_back(ITV) ;
        }else if(x + i > n && i - x >= 1){
            //one.insert(i - x) ;
            interval ITV ;
            ITV.fir = i - x + 1 ;
            ITV.sec = n ;
            itv.push_back(ITV) ;
        }
    }

    vector<interval> itv1 ;
    vector<bool>vis(itv.size()) ;
    sort(itv.begin(), itv.end(), cmp) ;

    for(int i = 0 ; i < itv.size() ; ++i){
        if(vis[i]) continue ;
        vis[i] = true ;
        interval ITV1 = itv[i] ;
        for(int j = i + 1 ; j < itv.size() ; ++j){
            if(itv[j].fir <= ITV1.sec){
                ITV1.sec = max(ITV1.sec, itv[j].sec) ;
                vis[j] = true ;
            }else break ;
        }itv1.push_back(ITV1) ;
    }

    vector<bool> zero(n + 1) ;
    for(int i = 0 ; i < itv1.size() ; ++i){
        for(int j = itv1[i].fir ; j <= itv1[i].sec ; j++)
        zero[j] = 1 ;
    }

    set<int> one ;
    for(int i = 0 ; i <= n ; ++i) if(!zero[i]) one.insert(i) ;
    for(int i = 1 ; i <= n ; ++i) {
        int x = b[i] ; if(x == -1) continue ;
        if(x + i <= n && i - x >= 1){
            if(!one.count(x + i) && !one.count(i - x)){
                cout << "-1" ;
                return ;
            }
        }else if(x + i <= n && i - x < 1){
            if(!one.count(x + i)){
                cout << "-1" ;
                return ;
            } ;
        }else if(x + i > n && i - x >= 1){
            if(!one.count(i - x)){
                cout << "-1" ;
                return ;
            } ;
        }
    }for(int i = 1 ; i <= n ; ++i){
        if(zero[i]) cout << '0' ;
        else cout << '1' ;
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
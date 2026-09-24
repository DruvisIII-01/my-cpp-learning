#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n ; cin >> n ; 
    vector<int>b(n + 1) ; int sum = 0 ;
    for(int i = 1 ; i <= n ; ++i) {
        cin >> b[i] ;
        sum += b[i] ;
    }if(sum <= 0) {
        cout << "-1" ;
        return ;
    }

    vector<int>pos ;
    multiset<int, greater<int>>neg ;
    for(int i = 1 ; i <= n ; i++){
        if(b[i] > 0) pos.push_back(b[i]) ;
        else neg.insert(b[i]) ;
    }sort(pos.begin(), pos.end()) ;

    // for(int x : pos) cout << x << ' ' ;
    // cout << '\n' ;
    // cout << zero << '\n' ;
    // for(int x : neg) cout << x << ' ' ;
    // cout << '\n' ;
    // cout << '\n' ;

    vector<int>cons(1, 0) ;
    int cur = 0 ;
    for(int i = 0 ; i < pos.size() ; ++i){
        // cout << i << '\n' ;
        cons.push_back(pos[i]) ;

        cur += pos[i] ;
        if(neg.empty()) continue ;
        auto it = neg.lower_bound(-cur) ;

        if(it == neg.begin()) {
            while(!neg.empty() && *it + cur > 0){
                auto it1 = it ;
                if(it != neg.end()) it = next(it) ;
                cons.push_back(*it1) ; neg.erase(it1) ;
            }
        }

        while(!neg.empty() && it != neg.begin()){
            auto pr = prev(it) ;
            cons.push_back(*pr) ;
            cur += (*pr) ;
            neg.erase(pr) ;
            it = neg.lower_bound(-cur) ;
            if(it == neg.begin()) {
                while(!neg.empty() && *it + cur > 0){
                    auto it1 = it ;
                    if(it != neg.end()) it = next(it) ;
                    cons.push_back(*it1) ; neg.erase(it1) ;
                }
            }
        }
    }
    for(auto It = neg.rbegin() ; It != neg.rend() ; It++)
    cons.push_back(*It) ;
    
    // for(int x : cons) cout << x << ' ' ;
    // cout << '\n' ;

    int tmp = 0 ;
    vector<int> a ;
    for(int i = 1 ; i < cons.size() ; ++i){
        tmp += cons[i] ;
        a.push_back(tmp) ;
    }
    
    for(int i = 0 ; i < a.size() ; ++i) cout << a[i] << ' ' ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
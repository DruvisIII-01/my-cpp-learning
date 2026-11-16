#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    multiset<int> ms ; 
    vector<int> p(1) ;
    int sz = 0 ;

    string order ;
    while(cin >> order){
        if(order == "push"){
            int x ; cin >> x ;
            sz++ ;
            ms.insert(x) ;
            p.push_back(x) ;
        }
        else if(order == "pop"){
            auto it_mi = ms.begin() ;
            ms.erase(it_mi) ;
            sz-- ;
        }
        else if(order == "top"){
            auto it_mi = ms.begin() ;
            cout << *it_mi << endl ;
        }
        else if(order == "size") cout << sz << endl ;
        else if(order == "decrease"){
            int i, k ; cin >> i >> k ;
            auto it = ms.find(p[i]) ;
            ms.erase(it) ; p[i] = k ;
            ms.insert(k) ;
        }
    }
    return 0;
}
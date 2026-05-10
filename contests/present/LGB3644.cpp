#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int N ; cin >> N ;
    vector <vector <int>> a(N + 12, vector<int>()) ;
    vector <int> ru(N + 12) ;
    vector <int> ans ;

    for(int t = 1 ; t <= N ; t++){
        int x = -1 ; 
        while(x != 0){
            cin >> x ;
            if(x != 0){
                a[t].push_back(x) ;
                ru[x]++ ;
            }
        }
    }
    
    queue <int> que ;
    for(int i = 1 ; i <= N ; i++){
        if(ru[i] == 0) que.push(i) ;
    }
    while(!que.empty()){
        int tp = que.front() ;
        ans.push_back(tp) ;
        que.pop() ;
        for(auto x : a[tp]){
            ru[x]-- ;
            if(ru[x] == 0) que.push(x) ;
        }
    }
    for(auto x : ans) cout << x << ' ' ;
    return 0;
}
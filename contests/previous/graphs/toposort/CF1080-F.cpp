#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 3222 ;

struct Node{
    int a, b, c ; 
}func[MAXN] ;

bool cmp_func(struct Node& f1, struct Node& f2){
    int a1 = f1.a, b1 = f1.b, c1 = f1.c ;
    int a2 = f2.a, b2 = f2.b, c2 = f2.c ;
    
    int delta = (b1 - b2) * (b1 - b2) - 4 * (c1 - c2) * (a1 - a2) ;
    return (c1 > c2) && (((a1 == a2) && (b1 == b2)) || (delta < 0)) ;
}

void solve(){
    int n ; cin >> n ; 
    for(int t = 1 ; t <= n ; ++t) cin >> func[t].a >> func[t].b >> func[t].c ;

    vector<vector<int>> adj(n + 1, vector<int>()) ;
    vector<vector<int>> adq(n + 1, vector<int>()) ;
    vector<int> in(n + 1) ;
    vector<int> out(n + 1) ;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(cmp_func(func[i], func[j])) {
                adj[i].push_back(j) ;
                adq[j].push_back(i) ;
                out[i]++ ;
                in[j]++ ;
                //cout << "YES " ; 
            }//else cout << "NO " ;
        }//cout << endl ;
    }

    // for(int t = 1 ; t <= n ; ++t){
    //     for(int x : adj[t]) cout << x << ' ' ;
    //     cout << endl ;
    // }

    queue<int> que1 ;
    vector<int> dp1(n + 1) ;
    for(int t = 1 ; t <= n ; ++t){
        if(!in[t]) {
            dp1[t]++ ;
            que1.push(t) ;
        }
    }
    while(!que1.empty()){
        int frt = que1.front() ;
        que1.pop() ;
        for(int nb : adj[frt]){
            in[nb]-- ;
            dp1[nb] = max(dp1[nb], dp1[frt] + 1) ;
            if(!in[nb]) que1.push(nb) ;
        }
    }
    // for(int t = 1 ; t <= n ; ++t) cout << dp1[t] << ' ' ;
    // cout << endl ; 

    queue<int> que2 ;
    vector<int> dp2(n + 1) ;
    for(int t = 1 ; t <= n ; ++t){
        if(!out[t]){
            que2.push(t) ;
            dp2[t]++ ;
        }
    }
    while(!que2.empty()){
        int frt = que2.front() ;
        que2.pop() ;
        for(int nb : adq[frt]){
            out[nb]-- ;
            dp2[nb] = max(dp2[nb], dp2[frt] + 1) ;
            if(!out[nb]) que2.push(nb) ;
        }
    }
    // for(int t = 1 ; t <= n ; ++t) cout << dp2[t] << ' ' ;
    // cout << endl ; 
    for(int t = 1 ; t <= n ; ++t) cout << dp1[t] + dp2[t] - 1 << ' ' ; 
    for(int t = 1 ; t <= n ; ++t) func[t].a = func[t].b = func[t].c ; 
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define pii pair<int, int>

const int MAXN = 222222 ;
struct node{
    int to, next, wt ;
}e[MAXN] ;
int head[MAXN] ; int num = 0 ;

void add(int u, int v, int w){
    num++ ;
    e[num].to = v ;
    e[num].next = head[u] ;
    head[u] = num ;
    e[num].wt = w ;
}

void solve(){
    int n, a, b ; cin >> n >> a >> b ;

    num = 0 ;
    for(int t = 0 ; t <= n + 1 ; ++t){
        e[t].to = 0 ;
        e[t].next = 0 ;
        e[t].wt = 0 ;
        head[t] = 0 ;
    }

    for(int t = 1 ; t < n ; ++t){
        int u, v, w ; cin >> u >> v >> w ;
        add(u, v, w) ;
        add(v, u, w) ;
    }
    
    set<int> sB ; ; bool without = false ;
    vector<bool> visB(n + 1) ;
    queue<pii> qB ;
    qB.push({b, 0}) ;
    while(!qB.empty()){
        int frt = qB.front().first , fe = qB.front().second ;
        qB.pop() ; visB[frt] = true ;
        for(int i = head[frt] ; i ; i = e[i].next){
            int nb = e[i].to, wt = e[i].wt ;
            if(visB[nb]) continue ;
            int nwt = fe ^ wt ; qB.push({nb, nwt}) ;
            sB.insert(nwt) ;
            if(!nwt) without = true ;
        }
    } if(without) {
        cout << "YES" ;
        return ;
    }

    bool ans = false ; 
    vector<int> visA(n + 1) ;
    queue<pii> qA ;
    qA.push({a, 0}) ;
    while(!qA.empty()){
        int frt = qA.front().first, fe = qA.front().second ; 
        qA.pop() ; visA[frt] = true ;
        for(int i = head[frt] ; i ; i = e[i].next){
            int nb = e[i].to, wt = e[i].wt ;
            if(visA[nb]) continue ;
            int nwt = wt ^ fe ; 
            if(nb != b) {
                qA.push({nb, nwt}) ;
                if(sB.count(nwt)) ans = true ;
            }
        }
    }if(ans) cout << "YES" ;
    else cout << "NO" ;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << '\n' ;
    }
    return 0;
}
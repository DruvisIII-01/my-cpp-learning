#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n,k,p,m ;cin >> n >> k >> p >> m ;
    vector <int> a(n+1, 0) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    //n cards 
    //able to choose first to k-th cards
    //need to move p-th card as much as possible
    //need to control the cost of money below m
    int tmp = a[p], ans = 0 ;
    // sort(a.begin()+1, a.end()+n+1) ;
    int s1 = 0, s2 = 0 ;
    //s1 means the sum of min a to p-k min a
    //s2 means the sum of min a to n-k min a
    sort (a.begin()+1, a.begin()+p) ;
    for(int i = 1 ; i <= p-k ; i++) s1 += a[i] ;
    a[p] = LLONG_MAX ;
    sort (a.begin()+1, a.begin()+n+1) ;
    for(int i = 1 ; i <= n-k ; i++) s2 += a[i] ;
    //cout << tmp << ' ' << s1 << ' ' << s2 << endl ;
    if(p > k) {
        if(m < tmp+s1) {
            cout << 0 ;
            return ;
        }cout << 1+(m-(tmp+s1))/(tmp+s2) ;
    }else{
        if(m < tmp){
            cout << 0 ;
            return ;
        }cout << 1+(m-tmp)/(tmp+s2) ;
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
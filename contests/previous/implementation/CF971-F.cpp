#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n, q ; cin >> n >> q ;
    vector <int> a(n + 1) ;
    vector <int> pre(n + 1) ;
    int sum = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
        sum += a[i] ;
        pre[i] = pre[i - 1] + a[i] ;
    }

    //cout << sum << endl ;

    while(q--){
        int l, r ; cin >> l >> r ;
        int lt = (l + n - 1) / n, rt = (r + n - 1) / n ;
        //printf("lt = %d, rt = %d\n", lt, rt ) ;
        
        int lm = l % n, rm = r % n ;
        if(lm == 0) lm = n ;
        if(rm == 0) rm = n ;
        //printf("lm = %d, rm = %d\n", lm, rm ) ;
        
        int base = (rt - lt - 1) * sum ;
        
        int ri = (rt + rm - 1) % n, li = (lt + lm - 1) % n ;
        if(ri == 0) ri = n ;
        if(li == 0) li = n ;
        //printf("li = %d, ri = %d\n", li, ri ) ;

        if(rt == lt){
            if(1 + n - lt < lm || 1 + n - rt >= rm) cout << pre[ri] - pre[li - 1] ;
            else cout << sum - pre[li - 1] + pre[ri] ;
            cout << endl ;
            continue ;
        }

        int la = 0, ra = 0 ;
        if(1 + n - lt >= lm) la = sum - (pre[li - 1] - pre[lt - 1]) ;
        else la = pre[lt - 1] - pre[li - 1] ;
        if(1 + n - rt >= rm) ra = pre[ri] - pre[rt - 1] ;
        else ra = sum - (pre[rt - 1] - pre[ri]) ;
        //printf("la = %d, ra = %d\n", la, ra ) ;
        
        cout << ra + base + la << endl ;
    }
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
    }
    return 0;
}
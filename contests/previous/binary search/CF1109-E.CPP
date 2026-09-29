#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct seg{
    int fir ;
    int sec ;
} ;

void solve(){
    //input
    int n, q ; cin >> n >> q ;
    string s ; cin >> s ; s = '*' + s ;
    
    //construct final "beautiful" str
    string str1 = "*" ;
    for(int i = 1 ; i <= n ; ++i){
        if(i % 2) str1 += '1' ;
        else str1 += '0' ;
    }string str2 = "*" ;
    for(int i = 1 ; i <= n ; ++i){
        if(!(i % 2)) str2 += '1' ;
        else str2 += '0' ;
    }
    
    //find char of s need to change
    vector<bool> ch1(n + 1) ;
    for(int i = 1 ; i <= n ; ++i){
        if(s[i] != str1[i]) ch1[i] = 1 ; 
    }vector<bool> ch2(n + 1) ;
    for(int i = 1 ; i <= n ; ++i){
        if(s[i] != str2[i]) ch2[i] = 1 ;
    }

    //find all subsegs
    vector<seg> segs1 ;
    bool find = false ;
    int fi = -1 ; 
    int se = -1 ;
    for(int i = 1 ; i <= n ; i++){
        if(ch1[i]){
            if(!find){
                find = true ;
                fi = i ;
            }if(i == n){
                se = i ; 
                seg sg ; 
                sg.fir = fi ;
                sg.sec = se ;
                segs1.push_back(sg) ;
            }
        }else{
            if(find){
                find = false ;
                se = i - 1 ;
                seg sg ; 
                sg.fir = fi ;
                sg.sec = se ;
                segs1.push_back(sg) ;
            }
        }
    }vector<seg> segs2 ;
    find = false ;
    fi = -1 ; 
    se = -1 ;
    for(int i = 1 ; i <= n ; i++){
        if(ch2[i]){
            if(!find){
                find = true ;
                fi = i ;
            }if(i == n){
                se = i ; 
                seg sg ; 
                sg.fir = fi ;
                sg.sec = se ;
                segs2.push_back(sg) ;
            }
        }else{
            if(find){
                find = false ;
                se = i - 1 ;
                seg sg ; 
                sg.fir = fi ;
                sg.sec = se ;
                segs2.push_back(sg) ;
            }
        }
    }

    //queries
    int sz1 = segs1.size() ;
    int sz2 = segs2.size() ;
    for(int t = 1 ; t <= q ; ++t){
        int l, r, k ;
        cin >> l >> r >> k ;

        int cnt1 = 0 ;
        int cnt2 = 0 ;
        int L1 = -1, R1 = sz1 ;
        while(L1 + 1 != R1){
            int M1 = (L1 + R1) >> 1 ;
            if(segs1[M1].sec < l) L1 = M1 ;
            else R1 = M1 ; 
        }int L2 = -1, R2 = sz1 ;
        while(L2 + 1 != R2){
            int M2 = (L2 + R2) >> 1 ;
            if(segs1[M2].fir > r) R2 = M2 ;
            else L2 = M2 ;
        }cnt1 = R2 - L1 - 1 ;
        int L3 = -1, R3 = sz2 ; 
        while(L3 + 1 != R3){
            int M3 = (L3 + R3) >> 1 ;
            if(segs2[M3].sec < l) L3 = M3 ;
            else R3 = M3 ;
        }int L4 = -1, R4 = sz2 ; 
        while(L4 + 1 != R4){
            int M4 = (L4 + R4) >> 1 ;
            if(segs2[M4].fir > r) R4 = M4 ;
            else L4 = M4 ;
        }cnt2 = R4 - L3 - 1 ; 

        if(min(cnt2, cnt1) <= k) printf("YES\n") ;
        else printf("NO\n") ;
    }
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
    }
    return 0;
}
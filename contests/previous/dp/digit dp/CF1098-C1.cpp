#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;

string a ; 
int d1, d2 ; 
ll ans3 = LLONG_MAX ;
string x = "" ;

void dfs(int turn, int len, ll val, int status){
    if(turn >= len){
        ans3 = min(abs(val - stoll(x)), ans3) ;
        return ;
    }
    int digit = a[turn] - '0' ;
    if(!status){
        string tmp = x ;
        //d1
        x += d1 + '0' ;
        if(d1 > digit) dfs(turn + 1, len, val, 1) ;
        else if(d1 < digit) dfs(turn + 1, len, val, -1) ;
        else dfs(turn + 1, len, val, 0) ;
        x = tmp ;
        //d2
        x += d2 + '0' ;
        if(d2 > digit) dfs(turn + 1, len, val, 1) ;
        else if(d2 < digit) dfs(turn + 1, len, val, -1) ;
        else dfs(turn + 1, len, val, 0) ;
        x = tmp ;
    }else if(status == 1){
        string tmp = x ;
        x += d1 + '0' ;
        dfs(turn + 1, len, val, 1) ;
        x = tmp ;
    }
    else {
        string tmp = x ; 
        x += d2 + '0' ;
        dfs(turn + 1, len, val, -1) ;
        x = tmp ;
    }
}

void solve(){
    cin >> a ; 
    int n ; cin >> n ; 
    cin >> d1 >> d2 ;

    ll val_a = stoll(a) ;
    int len_a = a.size() ;

    bool perfect = true ;
    for(char ch : a){
        int x = ch - '0' ;
        if(x != d1 && x != d2) {perfect = false ; break ;}
    }
    if(perfect) {cout << 0 ; return ;}

    ll ans1 = LLONG_MAX ;
    if(len_a > 1) {
        string as1 = "" ;
        for(int turn = 1 ; turn <= len_a - 1 ; turn++){
            char to_add = (char)d2 +'0' ;
            as1 += to_add ; 
        }
        ans1 = abs(val_a - stoll(as1)) ;
    }

    ll ans2 = LLONG_MAX ;
    if(d1){
        string as21 = "" ;
        for(int turn = 1 ; turn <= len_a + 1 ; ++turn){
            char to_add = (char)d1 + '0' ;
            as21 += to_add ;
        }
        ans2 = abs(val_a - stoll(as21)) ;
    }else{
        string as22 = "" ;
        as22 += (char)d2 + '0' ;
        for(int turn = 1 ; turn <= len_a ; ++turn){
            char to_add = (char)d1 + '0' ;
            as22 += to_add ; 
        }
        ans2 = abs(val_a - stoll(as22)) ;
    }
    
    x = "" ;
    ans3 = LLONG_MAX ;
    dfs(0, len_a, val_a, 0) ;

    //cout << ans3 << endl ;
    ll ans = min({ans1, ans2, ans3}) ;
    cout << ans ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
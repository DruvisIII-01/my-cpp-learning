#include <bits/stdc++.h>
using namespace std ;

#define int long long

string a ;
int n ;
int d[100] ;

int ans3 = LLONG_MAX ;
string x = "" ;

void dfs(int turn, int len, int val, int status){
    if(turn >= len){
        ans3 = min(ans3, abs(val - stoll(x))) ;
        // cout << x << '\n' ;
        return ;
    }
    if(!status){
        int digit = (int)( a[turn] - '0') ;
        int e = -1 ;
        // for(int x1 : d){if(x1 == digit) e = digit ;}
        for(int i = 1 ; i <= n ; ++i) {if(d[i] == digit) {e = digit ; break ;}}
        if(e != -1){
            string tmp = x ;
            x += char( e + '0') ;
            dfs(turn + 1, len, val, 0) ;
            x = tmp ; 
            for(int i = n ; i > 0 ; i--){
                if(d[i] < digit) {
                    string tmp = x ;
                    x += char( d[i] + '0') ;
                    dfs(turn + 1, len, val, -1) ;
                    x = tmp ;
                    break ;
                }
            }
            for(int i = 1 ; i <= n ; ++i){
                if(d[i] > digit) {
                    string tmp = x ; 
                    x += char(d[i] + '0') ;
                    dfs(turn + 1, len, val, 1) ;
                    x = tmp ; 
                    break ;
                }
            }
        }else{
            for(int i = n ; i > 0 ; i--){
                if(d[i] < digit) {
                    string tmp = x ;
                    x += char( d[i] + '0') ;
                    dfs(turn + 1, len, val, -1) ;
                    x = tmp ;
                    break ;
                }
            }
            for(int i = 1 ; i <= n ; ++i){
                if(d[i] > digit) {
                    string tmp = x ; 
                    x += char(d[i] + '0') ;
                    dfs(turn + 1, len, val, 1) ;
                    x = tmp ; 
                    break ;
                }
            }
        }
    }else if(status == 1){
        string tmp = x ; 
        x += char(d[1] + '0') ;
        dfs(turn + 1, len, val, 1) ;
        x = tmp ;
    }else{
        string tmp = x ; 
        x += char(d[n] + '0') ;
        dfs(turn + 1, len, val, -1) ;
        x = tmp ;
    }
}

void solve(){
    cin >> a ; cin >> n ; 
    for(int turn = 1 ; turn < 100 ; ++turn) d[turn] = 0 ;
    for(int turn = 1 ; turn <= n ; ++turn) cin >> d[turn] ;
    int len_a = a.size() ;
    int val_a = stoll(a) ;
    if(n == 1 && d[n] == 0) {cout << val_a ; return ;}
    
    bool perfect = true ;
    for(char ch : a){
        int digit = (int)(ch - '0') ;
        bool find = false ;
        for(int i = 1 ; i <= n ; ++i) {if(d[i] == digit){ find = true ;break ;}}
        if(!find){ perfect = false ;break ;}
    }
    if(perfect){ cout << '0' ;return ;}

    int ans1 = LLONG_MAX ;
    string str1 = "" ;
    for(int turn = 1 ; turn <= len_a - 1 ; ++turn) str1 += char (d[n] + '0') ;
    if(str1.size() >= 1) ans1 = min(ans1, abs(stoll(str1) - val_a)) ;

    int ans2 = LLONG_MAX ;
    string str2 = "" ;
    if(n == 1 || (n >= 2 && d[1] != 0) ){
        for(int turn = 1 ; turn <= len_a + 1 ; ++turn) str2 += char (d[1] + '0') ;
        if(str2.size() >= 1) ans2 = min(ans2, abs(stoll(str2) - val_a)) ;
    }else if(n >= 2 && d[1] == 0){
        str2 += (char)( d[2] + '0') ;
        for(int turn = 1 ; turn <= len_a ; ++turn) str2 += '0' ;
        if(str2.size() >= 1) ans2 = min(ans2, abs(stoll(str2) - val_a)) ;
    }

    ans3 = LLONG_MAX ;
    x = "" ;
    dfs(0, len_a, val_a, 0) ;

    int ans = min({ans1, ans2, ans3}) ;
    // cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' <<endl ;
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
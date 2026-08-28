#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    string formal_time ; cin >> formal_time ;
    int x ; cin >> x ;
    int exact_time = 0 ;
    // minutes
    exact_time += ((formal_time[0] - '0') * 10 
    + (formal_time[1] - '0')) * 60 ;
    exact_time += ((formal_time[3] - '0') * 10 
    + (formal_time[4] - '0')) ;

    int et = exact_time ;
    int ans = 0 ;
    do{
        et += x ;
        et %= 1440 ;
        int hour = et / 60 ;
        int minute = et % 60 ;
        if(hour % 10 == minute / 10 
        && hour / 10 == minute % 10) ans++ ;
    }while(et != exact_time) ;
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
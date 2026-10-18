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

/* ######################################################################
 * 【题面与关键思路】The Clock
 * 题目链接：https://codeforces.com/problemset/problem/1692/D
 * 标签：难度 1100 | brute force,implementation
 *
 * 关键思路：枚举从给定时刻起每隔 x 分钟的所有时刻（含跨天循环），判断 HH:MM 是否为回文并计数。
 * ###################################################################### */

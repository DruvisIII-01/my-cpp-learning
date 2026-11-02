#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int N = -1 ;
    while(N != 0){
        cin >> N ; if(!N) break ; 
        int S = 0 ;
        for(int t = 1 ; t * t <= N ; ++t){
            if(!(N % t)){
                S += t ;
                if(N / t != t) S += N / t ;
            }
        }
        S -= N ;
        if(S > N) cout << "abundant number" ;
        else if(S < N) cout << "deficient number" ;
        else cout << "perfect number" ;
        cout << endl ;
    }
    return 0 ;
}

/* ##################################################################
 * 【题面与关键思路】DSHW02-B 盈数/亏数/完全数判定
 * 来源：学院课程作业（非竞赛题，无官方难度/标签）
 * 标签：难度 课程作业 | 数论, 枚举约数
 *
 * 关键思路：对每个 N 用 O(√N) 枚举约数求真因子和 S：S>N 为 abundant、S<N 为 deficient、S==N 为 perfect。
 * ################################################################## */

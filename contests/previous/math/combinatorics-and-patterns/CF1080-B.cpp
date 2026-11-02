#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool is_2power(int x) {
    return (x > 0) && ((x & (x - 1)) == 0) ;
}

void solve(){
    int n ; cin >> n ;
    vector<int> a(n + 1) ;
    vector<int> b(n + 1) ;
    for(int t = 1 ; t <= n ; ++t) {
        cin >> a[t] ;
        b[a[t]] = t ;
    }
    // for(int t = 1 ; t <= n ; ++t) cout << b[t] << ' ' ;
    // cout << endl ;

    bool ans = true ;
    for(int t = 1 ; t <= n ; ++t) {
        //printf("b[t] = %d t = %d\n", b[t], t) ;
        if(b[t] <= t){
            if((t % b[t]) != 0 || !(is_2power(t / b[t]))){
                ans = false ;
                break ;
            } 
        }else{
            if((b[t] % t) != 0 || !(is_2power(b[t] / t))){
                ans = false ;
                break ;
            } 
        }
    }if(ans) cout << "YES" ;
    else cout << "NO" ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】Heapify 1
 * 题目链接：https://codeforces.com/problemset/problem/2195/B
 * 标签：难度 900 | implementation, sortings
 *
 * 关键思路：给每个值记录它的位置 b[value]，逐值检查"位置与该值的比值是否为 2 的幂"，全部满足输出 YES。
 * ################################################################## */

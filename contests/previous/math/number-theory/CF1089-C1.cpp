#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n; cin >> n;
    vector <int> a(n + 1);
    vector <int> b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    // int x0 = gcd(a[1], a[2]), y0 = gcd(a[n - 1], a[n]),
    // ans = (a[1] != x0) + (a[n] != y0);
    // for(int i = 2; i <= n - 1; i++) {
    //     int x = gcd(a[i - 1], a[i]), y = gcd(a[i], a[i + 1]);
    //     if(x == y) ans += (a[i] != x); 
    // }cout << ans;
    vector <int> x(n + 1);
    for(int i = 1; i <= n - 1; i++) x[i] = gcd(a[i], a[i + 1]) ;
    int ans = (a[1] != x[1]) + (a[n] != x[n - 1]);
    for(int i = 2; i <= n - 1; i++) {
        // if(x[i - 1] == x[i]) ans += (a[i] != x[i]) ;
        int need = (x[i - 1] * x[i]) / gcd(x[i - 1], x[i]);
        if(need < a[i]) ans++;
    }cout << ans;
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
 * 【题面与关键思路】A Simple GCD Problem (Easy Version)
 * 题目链接：https://codeforces.com/problemset/problem/2210/C1
 * 标签：难度 1200 | greedy,number theory
 *
 * 关键思路：要求 a[i] | b[i] 且相邻 gcd 保持不变。结论：a[i] 能取的最小值是 gcd(a[i-1], b[i]) 与 gcd(a[i+1], b[i]) 的 lcm；逐一检查是否整除 b[i]。
 * ###################################################################### */

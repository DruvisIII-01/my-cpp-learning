#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> ans(n);
    vector<int> zero, one;  // 存放以0/1结尾的子序列编号
    int cnt = 0;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (!one.empty()) {
                int id = one.back(); one.pop_back();
                ans[i] = id;
                zero.push_back(id);
            } else {
                ++cnt;
                ans[i] = cnt;
                zero.push_back(cnt);
            }
        } else { // '1'
            if (!zero.empty()) {
                int id = zero.back(); zero.pop_back();
                ans[i] = id;
                one.push_back(id);
            } else {
                ++cnt;
                ans[i] = cnt;
                one.push_back(cnt);
            }
        }
    }
    
    cout << cnt << '\n';
    for (int x : ans) cout << x << ' ';
}


signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
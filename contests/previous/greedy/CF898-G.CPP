#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve() {
    string s; cin >> s;
    int totalA = count(s.begin(), s.end(), 'A');
    if (s.front() == 'B' || s.back() == 'B') {
        cout << totalA << '\n';
        return;
    }
    int minSeg = INT_MAX, cur = 0;
    for (char c : s) {
        if (c == 'A') cur++;
        else {
            minSeg = min(minSeg, cur);
            cur = 0;
        }
    }
    minSeg = min(minSeg, cur); // 最后一段
    cout << totalA - minSeg ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
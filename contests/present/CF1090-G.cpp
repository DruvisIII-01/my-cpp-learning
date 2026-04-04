#include <bits/stdc++.h>
using namespace std;

const int MOD = 676767677;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> b(n);
    vector<int> cnt(m, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cnt[b[i]]++;
    }
    
    // 邻居检查
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) {
            bool ok = false;
            if (i > 0 && b[i-1] < b[i]) ok = true;
            if (i+1 < n && b[i+1] < b[i]) ok = true;
            if (!ok) {
                cout << 0 << "\n";
                return;
            }
        }
    }
    
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) {
            ans = (ans * cnt[b[i] - 1]) % MOD;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
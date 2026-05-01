#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n + 1);
    vector<int> L(n, -1), R(n, -1);
    
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (L[a[i]] == -1) L[a[i]] = i;
        else R[a[i]] = i;
    }
    
    // 三个候选中心
    vector<int> can;
    can.push_back(L[0] + R[0]);   // 0出现2次
    can.push_back(2 * L[0]);      // 0出现1次(L[0]是中心)
    can.push_back(2 * R[0]);      // 0出现1次(R[0]是中心)
    
    int ans = 1;
    
    for (int C : can) {
        // 确定中心的实际位置
        // 如果C是中心坐标*2，实际中心位置是 C/2.0
        // 但我们用双指针扩展时，需要知道实际的左右边界
        
        int l, r;
        if (C % 2 == 0) {
            // 中心在某个位置上（整数位置）
            int center = C / 2;
            if (center < 1 || center > 2 * n) continue;
            l = center;
            r = center;
            // 扩展：当中心在位置center时，初始左右都在center
        } else {
            // 中心在两个位置之间（半整数位置）
            int center_left = C / 2;      // 左边的位置
            int center_right = C / 2 + 1; // 右边的位置
            if (center_left < 1 || center_right > 2 * n) continue;
            // 初始时，需要a[center_left] == a[center_right]才能形成回文
            if (a[center_left] != a[center_right]) continue;
            l = center_left;
            r = center_right;
        }
        
        // 向两边扩展找最长回文
        while (l - 1 >= 1 && r + 1 <= 2 * n && a[l - 1] == a[r + 1]) {
            l--;
            r++;
        }
        
        // 现在 [l, r] 是以C为中心的最长回文子数组
        // 检查它包含哪些数字（从0开始连续）
        vector<bool> vis(n, false);
        for (int i = l; i <= r; i++) {
            vis[a[i]] = true;
        }
        
        int mex = 0;
        while (mex < n && vis[mex]) mex++;
        ans = max(ans, mex);
    }
    
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ull unsigned long long

const int N = 2e5 + 5;
const int LIM = 1000;

int t, n;
ull a[N];
int vis[LIM + 5];
ull hs[LIM + 5];
vector<int> prime;
mt19937_64 rnd(time(0));

// 线性筛出 1000 以内的质数，并为每个小质数生成随机哈希
void init() {
    for (int i = 2; i <= LIM; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            prime.push_back(i);
            hs[i] = rnd();
        }
        for (int &j : prime) {
            int val = i * j;
            if (val > LIM) break;
            vis[val] = 1;
            if (i % j == 0) break;
        }
    }
}

// 对大质数（>1000）生成确定性哈希，保证不同大质数哈希不同
ull get(ull x) {
    x ^= x << 24;
    x *= 24;
    x ^= x << 25;
    x *= 25;
    x ^= x << 26;
    return x;
}

// 计算一个数的平方自由核的哈希值
ull geths(ull x) {
    ull res = 0;
    for (int &p : prime) {
        int cnt = 0;
        while (x % p == 0) {
            cnt ^= 1;
            x /= p;
        }
        if (cnt) res ^= hs[p];
    }
    if (x > 1) res ^= get(x); // 剩余的大质数
    return res;
}

void solve() {
    cin >> n;
    map<ull, int> mp;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = geths(a[i]);
        mp[a[i]]++;
    }

    ull now = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        now ^= a[i];
        ans += mp[now];
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init();
    cin >> t;
    while (t--) solve();
    return 0;
}
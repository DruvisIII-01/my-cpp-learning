#include "bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define endl '\n'
#define int long long
#define f first
#define mp make_pair
#define s second
using namespace std;

void solve(){
    int n, k, q; cin >> n >> k >> q;
    int a[n + 1]; for(int i = 1; i <= n; i++) cin >> a[i];
    map <int,int> m;
    multiset <int> tot;
    for(int i = 1; i <= n; i++) tot.insert(0);
    for(int i = 1; i < k; i++){
        tot.erase(tot.find(m[a[i] - i]));
        m[a[i] - i]++;
        tot.insert(m[a[i] - i]);
    }
    int ret[n + 1];
    for(int i = k; i <= n; i++){
        tot.erase(tot.find(m[a[i] - i]));
        m[a[i] - i]++;
        tot.insert(m[a[i] - i]);
        int p = i - k + 1;
        ret[p] = k - *tot.rbegin();
        tot.erase(tot.find(m[a[p] - p]));
        m[a[p] - p]--;
        tot.insert(m[a[p] - p]);
    }
    while(q--){
        int l, r ; cin >> l >> r;
        cout << ret[l] << endl;
    }
    tot.clear();
    m.clear();
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

/* ######################################################################
 * 【题面与关键思路】Yunli's Subarray Queries (easy version)
 * 题目链接：https://codeforces.com/problemset/problem/2009/G1
 * 标签：难度 1900 | binary search,data structures,two pointers
 *
 * 关键思路：询问区间内最大出现次数：map 计数 + multiset 维护频次，配合双指针/滑动窗口在移动端点时 O(log n) 更新频次多重集。
 * ###################################################################### */

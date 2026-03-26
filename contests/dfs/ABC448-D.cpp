#include <bits/stdc++.h>
using namespace std ;

//#define int long long
#define MAXN 224524

int cnt = 0 ;
//cnt表示到现在为止，路径中
//有多少节点存在相同的数值

vector <int> a(MAXN, 0) ;
vector <int> nxt[MAXN] ;
vector <bool> ans(MAXN, false) ;
set <int> st ;

void dfs(int v, int pv) {
    int del = st.count(a[v]) ;//del == 1当仅已经在pv及以前搜到a[v]
    cnt += (del == 1) ;
    st.insert(a[v]) ;//若del == 0，原来没有a[v]，就要插入a[v];
    //若del == 1，原来有a[v]，插入也无妨
    ans[v] = (cnt > 0) ;//如果从1到当前节点的路径存在重复出现的数
    //存在重复出现的数，那么当前节点的ans值就要改成1，反之保持0不变
    for(auto& nv : nxt[v]) {
        if(nv == pv) continue ;//dfs开始，表示开始从上往下搜索
        dfs(nv, v) ;//dfs结束，for循环遍历到下一个值，表示从左往右搜索
    }cnt -= (del == 1) ;//for循环结束，表示当前节点相邻节点均已搜索完毕
    if(!del) st.erase(a[v]) ;
}

// void wrong_dfs(int v, int pv) {
//     int f = st.count(a[v]) ;
//     st.insert(a[v]) ;
//     ans[v] = (f == 1) ;//ans[v] = 1 当仅当前插入值之前存在
//     //但是也可能在pv及以前就存在两个完全相同的值
//     for(auto& nv : nxt[v]) {
//         if(nv == pv) continue ;
//         dfs(nv, v) ;
//     }if(!f) st.erase(a[v]) ;
// }

signed main() {
    int n ;cin >> n ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    for(int t = 1 ; t < n ; t++) {
        int u, v ;cin >> u >> v ;
        nxt[u].push_back(v) ;
        nxt[v].push_back(u) ;
    }
    dfs(1,-1) ;
    for(int t = 1 ; t <=n ; t++) {
        if(ans[t]) cout << "Yes" << endl ;
        else cout << "No" << endl ;
    }
    return 0;
}
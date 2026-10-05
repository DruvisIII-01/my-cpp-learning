#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int N ; cin >> N ;
    vector <vector <int>> a(N + 12, vector<int>()) ;
    vector <int> ru(N + 12) ;
    vector <int> ans ;

    for(int t = 1 ; t <= N ; t++){
        int x = -1 ; 
        while(x != 0){
            cin >> x ;
            if(x != 0){
                a[t].push_back(x) ;
                ru[x]++ ;
            }
        }
    }
    
    queue <int> que ;
    for(int i = 1 ; i <= N ; i++){
        if(ru[i] == 0) que.push(i) ;
    }
    while(!que.empty()){
        int tp = que.front() ;
        ans.push_back(tp) ;
        que.pop() ;
        for(auto x : a[tp]){
            ru[x]-- ;
            if(ru[x] == 0) que.push(x) ;
        }
    }
    for(auto x : ans) cout << x << ' ' ;
    return 0;
}

/* ######################################################################
 * 【题面与关键思路】B3644 【模板】拓扑排序 / 家谱树
 * 题目链接：https://www.luogu.com.cn/problem/B3644
 * 标签：难度 洛谷 普及- | 拓扑排序
 *
 * 关键思路：BFS 拓扑排序模板：入度为 0 入队，逐点出队并把邻居入度减 1，减到 0 再入队；输出任意合法拓扑序。
 * ###################################################################### */

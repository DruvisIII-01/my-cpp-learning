#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int MAXN = 3333333 ; 
int cnt = 1 ;
int tree[MAXN][70] ;
int pass[MAXN] ;

int det(char ch){
    if(ch <= '9' && ch >= '0') return ch - '0' ;
    if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 10 ; 
    if(ch >= 'a' && ch <= 'z') return ch - 'a' + 36 ;
    return -1 ; 
}

void insert_trie(string str){
    int cur = 1 ; 
    pass[cur]++ ; 
    for(char ch : str){
        if(!tree[cur][det(ch)]) tree[cur][det(ch)] = (++cnt) ;
        cur = tree[cur][det(ch)] ;
        pass[cur]++ ; 
    }
}

int query_trie(string str){
    int cur = 1 ;
    for(char ch : str){
        if(!tree[cur][det(ch)]) return 0 ; 
        cur = tree[cur][det(ch)] ;
    }return pass[cur] ;
}

void solve(){
    int n, q ; cin >> n >> q ; cnt = 1 ;
    for(int t = 1 ; t <= n ; ++t){
        string str ; cin >> str ; 
        insert_trie(str) ;
    }

    for(int QWQ = 1 ; QWQ <= q ; ++QWQ) {
        string tmp ; cin >> tmp ; 
        cout << query_trie(tmp) << endl ;
    }
    for(int t = 0 ; t <= cnt ; ++t){
        for(int i = 0 ; i <= 69 ; ++i) tree[t][i] = 0 ; 
        pass[t] = 0 ; 
    }
}

signed main() {
    int T ;cin >> T ;
    while(T--) solve() ;
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】P8306 【模板】字典树
 * 题目链接：https://www.luogu.com.cn/problem/P8306
 * 标签：难度 洛谷 普及+/提高 | Trie 字典树
 *
 * 关键思路：Trie 模板：每个节点开 66 个字符分支（数字/大写/小写映射到 0..61），插入时沿路径把 pass[节点] +1，查询时返回末尾节点的 pass 值（即该前缀出现的次数）。
 * ################################################################## */

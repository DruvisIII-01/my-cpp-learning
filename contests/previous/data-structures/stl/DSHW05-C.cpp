#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    multiset<int> ms ; 
    vector<int> p(1) ;
    int sz = 0 ;

    string order ;
    while(cin >> order){
        if(order == "push"){
            int x ; cin >> x ;
            sz++ ;
            ms.insert(x) ;
            p.push_back(x) ;
        }
        else if(order == "pop"){
            auto it_mi = ms.begin() ;
            ms.erase(it_mi) ;
            sz-- ;
        }
        else if(order == "top"){
            auto it_mi = ms.begin() ;
            cout << *it_mi << endl ;
        }
        else if(order == "size") cout << sz << endl ;
        else if(order == "decrease"){
            int i, k ; cin >> i >> k ;
            auto it = ms.find(p[i]) ;
            ms.erase(it) ; p[i] = k ;
            ms.insert(k) ;
        }
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】DSHW05-C 可修改的堆（multiset）
 * 来源：数据结构课程作业（非竞赛题，无官方难度/标签）
 * 标签：课程作业 | multiset, 堆
 *
 * 关键思路：用 multiset 维护全部元素以支持 push/pop/top（取最小值），并用数组 p 记录每个位置的原值，decrease 操作先 find 删除旧值再插入新值。
 * ################################################################## */

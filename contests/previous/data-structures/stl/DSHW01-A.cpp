#include <bits/stdc++.h>
using namespace std ;

//#define int long long
int a[224524] ;

signed main() {
    int cap = 10, sz = 0 ;
    string op ; 
    while(cin >> op){
        if(op == "append"){
            int x ; cin >> x ;
            if(cap == sz) cap <<= 1 ;
            a[sz++] = x ;
        }
        else if(op == "set"){ int x, y ; cin >> x >> y ; a[x] = y ;}
        else if(op == "erase"){
            int x ; cin >> x ;
            for(int t = x ; t < sz - 1 ; ++t) a[t] = a[t + 1] ;
            sz-- ;
            if(sz < cap / 2) cap >>= 1 ;
        }
        else if(op == "get"){ int x ; cin >> x ; cout << a[x] << endl ;}
        else if(op == "size"){ cout << sz << endl ;}
        else if(op == "capacity"){ cout << cap << endl ;}
        else if(op == "print"){
            for(int t = 0 ; t < sz ; ++t) cout << a[t] << ' ' ;
            cout << endl ;
        }
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】DSHW01-A 变长数组模拟
 * 来源：学院课程作业（非竞赛题，无官方难度/标签）
 * 标签：难度 课程作业 | 模拟, 动态数组
 *
 * 关键思路：用容量 cap 与长度 sz 模拟 vector：append 时容量翻倍、erase 时左移并缩容，支持 set/get/size/capacity/print。
 * ################################################################## */

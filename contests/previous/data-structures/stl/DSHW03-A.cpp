#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int sz ; cin >> sz ;
    deque<int> dq ;
    int cur = 0 ; string order ;
    while(cin >> order){
        if(order == "enqueue"){
            int x ; cin >> x ;
            if(cur == sz) cout << "Overflow" << endl ;
            else{
                dq.push_back(x) ;
                cur++ ;
            }
        }
        else if(order == "dequeue"){
            if(!cur) cout << "Underflow" << endl ;
            else {
                dq.pop_front() ;
                cur-- ;
            }
        }
        else if(order == "front") {
            if(!cur) cout << "-1" << endl ;
            else cout << dq.front() << endl ;
        }
        else if(order == "rear"){
            if(!cur) cout << "-1" << endl ;
            else cout << dq.back() << endl ;
        }
        else if(order == "isEmpty"){
            if(!cur) cout << "True" << endl ;
            else cout << "False" << endl ;
        }
        else if(order == "isFull"){
            if(cur == sz) cout << "True" << endl ;
            else cout << "False" << endl ;
        }
    } 
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】DSHW03-A 循环队列/受限队列
 * 来源：学院课程作业（非竞赛题，无官方难度/标签）
 * 标签：难度 课程作业 | 队列, deque
 *
 * 关键思路：用 deque 维护定长队列：enqueue 判断 Overflow、dequeue 判断 Underflow，并支持 front/back 查询。
 * ################################################################## */

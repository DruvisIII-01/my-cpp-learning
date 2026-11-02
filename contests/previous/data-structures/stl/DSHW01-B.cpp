#include <bits/stdc++.h>
using namespace std ;

#define int long long
struct Node{
    int v ;
    struct Node* next ;
} ;
struct Linkedlist{ Node* head ;} ;

signed main() {
    string op ;
    struct Linkedlist L ; L.head = nullptr ;
    struct Node* Dummy = new Node{-1, L.head} ;
    while(cin >> op){
        if(op == "pushFront"){
            int x ; cin >> x ;
            Dummy -> next = new Node{x, Dummy -> next} ;
        } 
        else if(op == "pushBack"){
            int x ; cin >> x ;
            struct Node* nd = Dummy ;
            while(nd -> next) nd = nd -> next ;
            nd -> next = new Node{x, nullptr} ;
        }
        else if(op == "search"){
            int x, ans = 0 ; cin >> x ;
            struct Node* nd = Dummy -> next ;
            while(nd){
                if(x == nd -> v){
                    ans = 1 ;
                    break ;
                }nd = nd -> next ;
            }cout << ans << endl ;
        }
        else if(op == "remove"){
            int x ; cin >> x ;
            struct Node* nd = Dummy -> next ;
            struct Node* prev = Dummy ;
            while(nd){
                if(x == nd -> v){
                    prev -> next = nd -> next ;
                    nd -> next = nullptr ;
                    break ;
                }prev = nd ;
                nd = nd -> next ;
            }
        }
        else if(op == "print"){
            struct Node* nd = Dummy -> next ;
            while(nd){
                cout << nd -> v << ' ' ;
                nd = nd -> next ;
            }cout << endl ;
        }
    }
    return 0;
}

/* ##################################################################
 * 【题面与关键思路】DSHW01-B 链表模拟
 * 来源：学院课程作业（非竞赛题，无官方难度/标签）
 * 标签：难度 课程作业 | 链表
 *
 * 关键思路：用带哨兵头结点（Dummy）的单链表实现 pushFront/pushBack/search/erase 等操作，注意指针的边界处理。
 * ################################################################## */

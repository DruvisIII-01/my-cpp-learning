#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
signed main() {
    cin >> T;
    while (T --) {
        int qq, l = 0, cool = 0, sum = 0; 
        cin >> qq;
        deque<int> q, lq;
        for (int i = 1; i <= qq; ++ i) {
            int s;
            cin >> s;
            if (s == 1) {
            	cool += sum - l * q.back();
                lq.push_back(q.back());
                lq.pop_front();
                q.push_front(q.back());
                q.pop_back();
                cout << cool << endl;
            }else if(s == 2) {
                cool = (l + 1) * sum - cool;
                swap(q, lq);
                cout << cool << endl;
            }else {
                int k;
                cin >> k;
                q.push_back(k), lq.push_front(k);
                l ++;
                cool += l * k;
                sum += k;
                cout << cool << endl;
            }
        }
    }
}

/* ######################################################################
 * 【题面与关键思路】Chimpanzini Bananini（双端队列维护两两乘积和）
 * 题目链接：https://codeforces.com/problemset/problem/2094/G
 * 标签：难度 1700 | data structures,implementation,math
 *
 * 关键思路：维护环上所有有序对的 sum(a[i]*a[j], i<j)：用两个双端队列 + 维护 sum 与 cool，操作 1 的旋转可由 cool -> l*sum - cool 推出，O(1) 摊销。这题的关键是发现旋转后两两乘积和的变换公式。
 * ###################################################################### */

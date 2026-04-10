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

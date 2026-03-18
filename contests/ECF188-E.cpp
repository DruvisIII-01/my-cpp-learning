#include <bits/stdc++.h>
using namespace std ;

#define int long long

int f(int x){
    int res = 0 ;
    while(x != 0) {
        res += x % 10 ;
        x /= 10 ;
    }
    return res ;
}

void solve(){
    string s ; cin >> s ;
    int n = s.size() ;
    if(n == 1){
        cout << s ;
        return ;
    }
    int s_sum = 0 ;
    vector <int> s_cnt(10) ;
    for(auto x : s){
        s_sum += x - '0' ;
        s_cnt[x - '0']++ ;
    }
    for(int x = 1 ; x <= n*9 ; x++){
        //x 表示第一次从s中取数求出的中间和
        int tx = x ;
        string sx = to_string(tx) ;
        //sx 表示 x 经过若干次累计求和得到的字符串
        while(tx > 9){
            tx = f(tx) ;
            sx += to_string(tx) ;
        }
        int sx_sum = 0 ;
        vector <int> sx_cnt(10) ;
        for(auto d : sx){
            sx_sum += d - '0' ;
            sx_cnt[d - '0']++ ;
        }
        bool can = true ;
        for(int i = 0 ; i < 10 ; i++){
            if(sx_cnt[i] > s_cnt[i]) {
                can = false ;
                break ;
            }
        }
        if(x != s_sum - sx_sum) can = false ;
        if(can) {
            string res = "" ;
            for(int i = 9 ; i >= 0 ;i--){
                for(int t = 1 ; t <= s_cnt[i] - sx_cnt[i] ; t++){
                    res.push_back(char(i + '0')) ;
                }
            }
            res += sx ;
            cout << res ;
            return ;
        }
    }
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        solve() ;
        cout << endl ;
    }
    return 0;
}
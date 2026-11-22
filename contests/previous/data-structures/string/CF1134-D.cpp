#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    string str;
    cin >> str;

    int ans = 0;

    while(true){
        bool ok = true;
        char mx = 'a';

        for(int i = 0; i < n; ++i){
            if(str[i] != str[n - 1 - i]){
                ok = false;
                mx = max(mx, str[i]);
            }
        }

        if(ok) break;

        string nxt;
        nxt.reserve(n);

        for(char ch : str){
            if(ch == mx) nxt.push_back((char)(ch - 1));
            else nxt.push_back(ch);
        }

        str.swap(nxt);
        ++ans;
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}
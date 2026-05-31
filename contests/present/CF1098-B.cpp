#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;
        
        int ans = -1 ;
        if (n <= 3) {
            ans = 1 ;
        }
        else{
            int d = min(abs(x1 - x2), n - abs(x1 - x2)); 
            ans = d + k ;
        }
        cout << ans << endl ;
    }
    return 0;
}
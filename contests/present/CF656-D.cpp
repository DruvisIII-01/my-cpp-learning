#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(const string& s, int l, int r, char c){
    if(l == r){
        if(c == s[l]) return 0 ; 
        else return 1 ;
    }
    int mid = (l + r) >> 1 ;
    int Lchange = 0;
    int Rchange = 0 ;
    for(int i = l ; i <= mid ; i++){
        if(s[i] != c) Lchange++ ;
    }int ans1 = Lchange + solve(s, mid + 1, r, c + 1) ;
    for(int i = mid + 1 ; i <= r ; i++){
        if(s[i] != c) Rchange++ ;
    }int ans2 = Rchange + solve(s, l, mid, c + 1) ;
    return min(ans1, ans2) ;
}

signed main() {
    int T ;cin >> T ;
    while(T--) {
        int n ; cin >> n ;
        string s ; cin >> s ;
        int ans = solve(s, 0, n - 1, 'a') ;
        cout << ans << endl ;
    }
    return 0;
}
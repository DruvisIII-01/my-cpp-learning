#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int N = -1 ;
    while(N != 0){
        cin >> N ; if(!N) break ; 
        int S = 0 ;
        for(int t = 1 ; t * t <= N ; ++t){
            if(!(N % t)){
                S += t ;
                if(N / t != t) S += N / t ;
            }
        }
        S -= N ;
        if(S > N) cout << "abundant number" ;
        else if(S < N) cout << "deficient number" ;
        else cout << "perfect number" ;
        cout << endl ;
    }
    return 0 ;
}
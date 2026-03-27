#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
    int n ;cin >> n ;
    vector <int> a(n+1, 0) ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    vector <int> dp(0) ;
    dp.push_back(a[1]) ;
    for(int i = 2 ; i <= n ; i++) {
        int sz = dp.size() ;
        //如果a[i]比dp中的每一个元素都大
        if(a[i] > dp[sz-1]) dp.push_back(a[i]) ;
        else {
            int left = -1, right = sz ;
            //否则，二分查找找出第一个大于等于a[i]的数
            while(left != right-1){
                int mid = (left+right) >> 1 ;
                if(dp[mid] < a[i]) left = mid ;
                else right = mid ;
            }
            dp[right] = a[i] ;
        }
    }
    cout << n-dp.size() ;
    return 0;
}
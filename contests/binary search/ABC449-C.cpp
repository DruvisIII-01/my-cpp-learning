#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main() {
	int n0, l, r ; cin >> n0 >> l >> r ;
	string s ; cin >> s ;
	vector <int> hsh[26] ;
	for(int i = 0 ; i < n0 ; i++) {
		hsh[s[i] - 'a'].push_back(i) ;
	}
	int cnt = 0 ;
	for(int t = 0 ; t < 26 ; t++) {
		vector <int> a ; 
		for(auto x : hsh[t]) a.push_back(x) ;
		int n = a.size() ;
		if(n <= 1) continue ;
		for(int i = 0 ; i < n ; i++){
			//枚举数组a中每一个每一个成员作为起点
			//用二分查找找到第一个j
			//s.t. a[j] - a[i] >= l ;
			if(a[n - 1] - a[i] < l) break ;
			int L1 = i, R1 = n ;
			while(R1 != L1 + 1){
				int M1 = (R1 + L1) >> 1 ;
				if(a[M1] - a[i] >= l) R1 = M1 ;
				else L1 = M1 ;
			}
			//a[R1] 是第一个满足 a[j] - a[i] >= l 的元素
			//再用二分查找找到第一个j
			//s.t. a[j] - a[i] > r ;
			if(a[n - 1] - a[i] <= r) {
				cnt += n - R1 ;
				continue ;
			}
			int L2 = i, R2 = n ;
			while(R2 != L2 + 1){
				int M2 = (R2 + L2) >> 1 ;
				if(a[M2] - a[i] > r) R2 = M2 ;
				else L2 = M2 ;
			}
			//a[R2 - 1] 是最后一个满足a[j] - a[i] <= r 的元素
			cnt += R2 - R1 ; 
		}
	}
	cout << cnt << endl ;
	return 0;
}
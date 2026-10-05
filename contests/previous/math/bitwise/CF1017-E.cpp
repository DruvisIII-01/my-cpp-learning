#include <bits/stdc++.h>
using namespace std;

#define int long long

int t,n;
int a[224524];
int er[32][2];

void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			bool x = a[i]&(1<<j);
			er[j][x]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int tp=0;
		for(int j=0;j<=30;j++){
			bool x= a[i]&(1<<j);
			tp+=er[j][1-x]*(1<<j);
		}
		ans = max(ans,tp);
	}
	cout<<ans;
}

void cl(){
	for(int i=0;i<32;i++){
		for(int j=0;j<=1;j++){
			er[i][j]=0;
		}
	}
}
signed main() {
	cin>>t;
	while(t--){
		solve();
		cl();
		cout<<endl;	
	}
	return 0;
}

/* ######################################################################
 * 【题面与关键思路】Boneca Ambalabu
 * 题目链接：https://codeforces.com/problemset/problem/2094/E
 * 标签：难度 1200 | bitmasks
 *
 * 关键思路：对每一位统计 0 和 1 的个数，选某个 a[i] 使 sum(a[i] xor a[j]) 最大；逐位算贡献 2^k * (该位与 a[i] 相反的个数)，取最大。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std;

#define int long long

int t;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	if(m%k!=0){
		int time =0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				time++;
				int ans = time%k;
				if(!ans) cout<<k;
				else cout<<ans;
				cout<<' ';
			}
			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==0){
				cout<<j%k+1<<' ';
			}
			else{
				int ans = j%k;
			    if(!ans) cout<<k;
				else cout<<ans;
				cout<<' ';	
			}
		}
		cout<<endl;
	}
}

signed main() {
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

/* ######################################################################
 * 【题面与关键思路】Trulimero Trulicina
 * 题目链接：https://codeforces.com/problemset/problem/2094/F
 * 标签：难度 1600 | constructive algorithms
 *
 * 关键思路：把 1..n 排列成每行相邻数的差都不等于 1：按 j mod k 的循环移位规律输出（k 为每行长度）。
 * ###################################################################### */

#include <bits/stdc++.h>
using namespace std;

int t;
int pg[2222][2222];

void solve(){
	int n;cin>>n;
	int p[2222]={0};
	bool vis[2222]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>pg[i][j];
			p[i+j]=pg[i][j];
			vis[p[i+j]]=1;
		}
	}
	for(int i=1;i<=n*2;i++){
		if(!vis[i]){
			p[1]=i;
			break;
		}
	}
	for(int i=1;i<=n*2;i++){
		cout<<p[i]<<' ';
	}
}
int main() {
	cin>>t;
	while(t--){
		solve();
		cout<<endl;	
	}
	return 0;
}

/* ######################################################################
 * 【题面与关键思路】Brr Brrr Patapim
 * 题目链接：https://codeforces.com/problemset/problem/2094/C
 * 标签：难度 900 | math
 *
 * 关键思路：n×n 网格给出排列相邻两项之和 p[i]+p[i+1]，用 p[i+j]=a[i][j] 还原，再用 vis 找出唯一没出现的数放到 p[1]。
 * ###################################################################### */

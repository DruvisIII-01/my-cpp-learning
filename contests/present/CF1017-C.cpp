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
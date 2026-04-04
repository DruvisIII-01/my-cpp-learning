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
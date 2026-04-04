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
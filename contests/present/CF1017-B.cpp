#include <bits/stdc++.h>
using namespace std;

int t;

void solve(){
	int n,m,l,r;
	cin>>n>>m>>l>>r;
	int tp = m;
	while(tp<n){
		if(l<0&&tp<n) {
			l++;tp++;
		}
		if(r>0&&tp<n){
			r--;tp++;
		}
	}
	cout<<l<<' '<<r;
}
int main() {
	cin>>t;
	while(t--){
		solve();
		cout<<endl;	
	}
	return 0;
}
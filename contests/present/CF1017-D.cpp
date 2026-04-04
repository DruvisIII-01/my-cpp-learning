#include <bits/stdc++.h>
using namespace std;

int t;

void solve(){
    string sa,sb;
	cin>>sa>>sb;
	int la = sa.size(),lb=sb.size();
	
	if(sa[0]!=sb[0]) {
		cout<<"NO";
		return;
	}
	
	vector<int> a;
	vector<int> b;
	int left=0,right;
	for(right=0;right<la;right++){
		if(sa[right]!=sa[left]){
			a.push_back(right-left);
			left=right;
		}
	}a.push_back(right-left);
	int zuo=0,you;
	for(you=0;you<lb;you++){
		if(sb[you]!=sb[zuo]){
			b.push_back(you-zuo);
			zuo=you;
		}
	}b.push_back(you-zuo);
	
	// for(int i=0;i<a.size();i++){
		// cout<<a[i]<<' ';
	// }cout<<endl;
	// for(int i=0;i<b.size();i++){
		// cout<<b[i]<<' ';
	// }cout<<endl;
	
	if(b.size()!=a.size()){
		cout<<"NO";
		return;
	}
	int sz=a.size();
	for(int i=0;i<sz;i++){
		if(a[i]*2<b[i]||a[i]>b[i]){
			cout<<"NO";
			return;
		}
	}
	cout<<"YES";
	
	a.clear();
	b.clear();
}
int main() {
	cin>>t;
	while(t--){
		solve();
		cout<<endl;	
	}
	return 0;
}
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

/* ######################################################################
 * 【题面与关键思路】Tung Tung Sahur
 * 题目链接：https://codeforces.com/problemset/problem/2094/D
 * 标签：难度 1100 | greedy,strings,two pointers
 *
 * 关键思路：把两个串都划分成"极小连续相同字符段"，比较段数与每段长度是否满足 a[i] <= b[i] <= 2a[i]；分类讨论输出。
 * ###################################################################### */

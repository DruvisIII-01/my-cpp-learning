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

/* ######################################################################
 * 【题面与关键思路】Bobritto Bandito
 * 题目链接：https://codeforces.com/problemset/problem/2094/B
 * 标签：难度 800 | brute force, constructive algorithms
 *
 * 关键思路：答案不唯一：从一个含 0 的长度 m 的区间出发，左右各扩展若干格把长度补到 n，输出任意合法区间即可。
 * ###################################################################### */

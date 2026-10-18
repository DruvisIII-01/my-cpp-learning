#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;

long long d[MAXN],a[MAXN],b[MAXN],f[MAXN],n,t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);//加快输入输出 
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
		}
		
		//计算差值 
		for(int i=1;i<=n;i++)
		{
			d[i]=b[i]-a[i];
		}
		
		//初始化，由于之前数组被使用过 
		f[n]=0;
		
		//开始从右往左递推 
		for(int i=n;i>=2;i--) 
		{
			f[i-1]=max((long long)0,f[i]-d[i]);
		}
		
		//判断
		if(f[1]<=d[1]) 
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	
	return 0;
}

/* ######################################################################
 * 【题面与关键思路】An Alternative Way
 * 题目链接：https://codeforces.com/problemset/problem/2241/D
 * 标签：难度 1100 | dp,greedy,math
 *
 * 关键思路：记 d[i] = b[i] − a[i]。操作只能"把 a[i] 减 1 并把 a[i-1] 加 1"，所以只能把多余的差值一步步往前推。从右往左递推 f[i-1] = max(0, f[i] − d[i])，表示位置 i 需要向前传递的量；最后 f[1] ≤ d[1] 则 YES，否则 NO。注意从右往左、且 first element 无法被减小。
 * ###################################################################### */

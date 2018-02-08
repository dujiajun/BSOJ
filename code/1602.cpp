#include<iostream>
#include<algorithm>
using namespace std;
int n,k,p,t,f[10005]={0};
struct th{int st,l;}w[10005]={0};
bool cmp(th t1,th t2){return t1.st<t2.st;}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>p>>t;
		w[i].st=p;
		w[i].l=t;
	}
	sort(w+1,w+k+1,cmp);
	for(int i=n;i>=1;i--) 
	{
		if(i!=w[k].st)f[i]=f[i+1]+1;
		else 
		while(w[k].st==i)
		{
			f[i]=max(f[i],f[i+w[k].l]);
			k--;
		}
	}
	cout<<f[1];
	return 0;
}
/*
15 6
1 2
1 6
4 11
8 5
8 1
11 5
*/
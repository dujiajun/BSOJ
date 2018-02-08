#include<iostream>
using namespace std;
int v[100]={0},q[100]={0},l[100]={0},r[100]={0},w[100]={0},f[5005]={0},n,m,i,j;
void init()
{
	cin>>n>>m;n/=10;
	for(i=1;i<=m;i++)
	{
		cin>>v[i]>>w[i]>>q[i];
		v[i]/=10;
		w[i]=v[i]*w[i];
		if(q[i])
		{
			if(l[q[i]])r[q[i]]=i;
			else l[q[i]]=i;
		}
	}
}

void dp()
{
	for(i=1;i<=m;i++)
	{
		if(q[i])continue;
		for(j=n;j>=v[i];j--)
		{
			f[j]=max(f[j],f[j-v[i]]+w[i]);
			
			if(l[i]&&j>=v[i]+v[l[i]])
			f[j]=max(f[j],f[j-v[i]-v[l[i]]]+w[i]+w[l[i]]);
			
			if(r[i]&&j>=v[i]+v[r[i]])
			f[j]=max(f[j],f[j-v[i]-v[r[i]]]+w[i]+w[r[i]]);
			
			if(l[i]&&j>=v[i]+v[l[i]]+v[r[i]])
			f[j]=max(f[j],f[j-v[i]-v[l[i]]-v[r[i]]]+w[i]+w[l[i]]+w[r[i]]);
			
		}
	}
}
void output()
{
	if(f[n])cout<<f[n];
	cout<<0<<endl;
}
int main()
{
	init();
	dp();
	output();
	return 0;
}
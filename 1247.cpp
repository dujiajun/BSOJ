#include<iostream>
using namespace std;
int n,k,prt[105],a,b,f1,f2,num[105],maxx=0,bj[105],cnt;
int getfa(int x)
{
	if(x==prt[x])return x;
	return prt[x]=getfa(prt[x]);
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){prt[i]=i;num[i]=1;}
	for(int i=1;i<=k;i++)
	{
		cin>>a>>b;
		f1=getfa(a);f2=getfa(b);
		if(f1!=f2)
		{
			num[f2]+=num[f1];
			prt[f1]=f2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		f1=getfa(i);
		if(!bj[f1]){cnt++;bj[f1]=1;}
		maxx=max(maxx,num[f1]);
	}
	cout<<cnt<<" "<<maxx<<endl;
	return 0;
}
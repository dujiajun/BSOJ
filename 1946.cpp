#include<iostream>
using namespace std;
int f[10001][105]={0},into[10001]={0},q[10001]={0},n,m,total=0;
void init()
{
	int a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		into[a]++;
		f[b][++f[b][0]]=a;
	}
}
bool topsort()
{
	int t=0,num=0,add=100;
	while(num<n)
	{
		t=0;
		for(int i=1;i<=n;i++)
			if(into[i]==0){t++;q[t]=i;num++;into[i]=0x7fffffff;}
		total+=t*add;
		add++;
		if(t==0)return false;
		for(int i=1;i<=t;i++)
			for(int j=1;j<=f[q[i]][0];j++)into[f[q[i]][j]]--;
	}
	return true;
}
int main()
{
	init();
	if(topsort()==0)cout<<"Poor Xed"<<endl;
	else cout<<total<<endl;
	return 0;
}
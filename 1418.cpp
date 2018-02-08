#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct tom{int a,b,v;tom(){a=b=v=0;}}toms[30001];
bool cmp(tom t1,tom t2){return t1.b<t2.b;}

int f[100005]={0},m=0,ma=0;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>toms[i].a>>toms[i].b>>toms[i].v;
		m=max(m,toms[i].b);
	}
	sort(toms+1,toms+n+1,cmp);
	int i=1;
	for(int j=0;j<=m;j++)
	{
		if(ma>f[j])f[j]=ma;
		while(toms[i].b==j)
		{
			f[j]=max(f[j],f[toms[i].a]+toms[i].v);
			i++;
		}
		if(ma<f[j])ma=f[j];
	}
	cout<<f[m];
	return 0;
}
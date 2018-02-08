#include<iostream>
#include<algorithm>
using namespace std;
int n,f[1005]={0},ans=0;
struct edge{int st,ed;}w[1005];
bool cmp(edge e1,edge e2){return e1.ed<e2.ed;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i].st>>w[i].ed;
	sort(w+1,w+n+1,cmp);
	int s=w[1].ed;f[1]=w[1].ed-w[1].st+1;
	for(int i=2;i<=n;i++)
	for(int j=i-1;j>=0;j--)
		if(w[i].st>w[j].ed){s=w[i].ed;f[i]=max(f[i],f[j]+w[i].ed-w[i].st+1);}
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}
/*
3
1 3
7 8
3 4
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0xfffffff;
struct eg{int x,y,v;}w[10005];
int m,n,father[505],ans[10005],f[10005];
bool cmp(eg x,eg y){return x.v<y.v;}
void init()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>w[i].x>>w[i].y>>w[i].v;
}
int findfather(int x)
{
	if(father[x]==x)return x;
	father[x]=findfather(father[x]);
	return father[x];
}
void kru(int flag)
{
	int t1,t2,k=0,sum=0;
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(i==flag)continue;
		t1=findfather(w[i].x);
		t2=findfather(w[i].y);
		if(t1!=t2)
		{
			father[t1]=t2;
			sum+=w[i].v;
			k++;
			if(flag==0)f[k]=i;
			if(k==n-1)break;
		}
	}
	if(k==n-1)ans[flag]=sum;
	else ans[flag]=-1;
}
int main()
{
	int k=0,minn=INF;
	init();
	sort(w+1,w+m+1,cmp);
	kru(0);
	cout<<"Cost: ";
	if(ans[0]!=-1)cout<<ans[0]<<endl;
	for(int i=1;i<=n-1;i++)
	{
		int j=f[i];
		kru(j);
		if(ans[j]!=-1&&ans[j]<minn){minn=ans[j];k=j;}
	}
	if(k==0)cout<<"Cost: "<<-1<<endl;
	else cout<<"Cost: "<<minn<<endl;
	return 0;
}
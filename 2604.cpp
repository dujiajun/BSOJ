#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int a[1000005]={0},head=1,tail=1,q[1000005]={0},ans,num[1000005]={0};
int n,k;
void minn()
{
	for(int i=2;i<=n;i++)
	{
		while(q[tail]>=a[i]&&tail>=head)tail--;
		tail++;
		q[tail]=a[i];
		num[tail]=i;
		while(num[head]<=i-k)head++;
		if(i>=k)cout<<q[head]<<" ";
	}
}
void maxx()
{
	for(int i=2;i<=n;i++)
	{
		while(q[tail]<=a[i]&&tail>=head)tail--;
		tail++;
		q[tail]=a[i];
		num[tail]=i;
		while(num[head]<=i-k)head++;
		if(i>=k)cout<<q[head]<<" ";
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	minn();
	memset(q,0,sizeof(q));memset(num,0,sizeof(num));
	head=1;tail=1;q[1]=a[1];
	cout<<endl;
	maxx();
	return 0;
}
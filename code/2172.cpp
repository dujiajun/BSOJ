#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005]={0},y[3],mo[3],d[3],h[3],mi[3];
long long s[5005]={0},t=0;
int ds[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int year){return (year%400==0)||(year%4==0&&year%100!=0);}
void gettime()
{
	t+=(y[2]-y[1])*365;
	for(int i=y[1];i<y[2];i++)if(check(i))t++;//处理yyyy-01-01-00:00至yyyy'-01-01-00:00
	for(int i=1;i<mo[1];i++)t-=ds[i];t-=d[1];
	for(int i=1;i<mo[2];i++)t+=ds[i];t+=d[2];
	t*=24;t-=h[1];t+=h[2];//转换为小时
	t*=60;t-=mi[1];t+=mi[2];//转换为分钟
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d-%d-%d-%d:%d",&y[1],&mo[1],&d[1],&h[1],&mi[1]);
	scanf("%d-%d-%d-%d:%d",&y[2],&mo[2],&d[2],&h[2],&mi[2]);
	gettime();
	sort(a+1,a+n+1);
	int i,ans=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]<=t){t-=a[i];ans++;}
		else break;
	}
	cout<<ans<<endl;
	return 0;
}
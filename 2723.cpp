#include<iostream>
#include<algorithm>
using namespace std;
long long a,b,lucky[30005],f[30005],sum,maxx;
bool v[30005];
int cnt;
void makelucky(long long x)
{
	if(x>b)return;
	if(x>0)lucky[++cnt]=x;
	makelucky(x*10+6);
	makelucky(x*10+8);
}
long long gcd(long long x,long long y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}
void calc(int x,int y,long long z)
{
	long long tmp;
	for(int i=x;i>=1;i--)
	{
		tmp=f[i]*z/gcd(z,f[i]);
		if(tmp>0&&tmp<=maxx)
		{
			if(y)sum+=maxx/tmp;
			else sum-=maxx/tmp;
			calc(i-1,!y,tmp);
		}
	}
}
long long solve(long long x)
{
	if(x<=5)return 0;
	sum=0;maxx=x;
	calc(f[0],1,1);
	return sum;
}
int main()
{
	cin>>a>>b;
	makelucky(0);
	sort(lucky+1,lucky+cnt+1);
	for(int i=1;i<=cnt;i++)
	if(v[i]==0)for(int j=i+1;j<=cnt;j++)if(lucky[j]%lucky[i]==0)v[j]=1;
	for(int i=1;i<=cnt;i++)if(v[i]==0)f[++f[0]]=lucky[i];
	cout<<solve(b)-solve(a-1)<<endl;
	return 0;
}
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=20000;
int pr[20000]={0},vst[maxn]={0};
int a,k=0,tmp;
long long n,num,cnt;
void makepr()
{
	for(int i=2;i<=maxn;i++)
	if(!vst[i])
	{
		pr[++k]=i;
		for(int j=i*2;j<=maxn;j+=i)vst[j]=1;
	}
}
void solve()
{
	scanf("%d",&n);num=n+1;cnt=1;
	for(int i=1;i<=k;i++)
	{
		if(num==1)break;
		a=0;
		while(num%pr[i]==0)
		{
			a++;
			num/=pr[i];
		}
		cnt=cnt*(a+1);
	}
	if(num!=1)cnt=cnt*2;
	printf("%d\n",cnt);
}
int main()
{
	makepr();
	cin>>tmp;
	while(tmp--)solve();
	return 0;
}
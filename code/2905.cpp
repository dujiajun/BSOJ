#include<iostream>
#include<cmath>
using namespace std;
int l,r,t[5000005]={0},pr[5000005]={0},k=0,ans=0,a[1000005]={0};
long long j=0;
void makepr()
{
	t[1]=1;
	int tt=sqrt(50005);
	for(int i=2;i<=tt;i++)
	if(!t[i])for(int j=i*i;j<=50005;j+=i)t[j]=1;
	for(int i=2;i<=50005;i++)if(!t[i])pr[++k]=i;
}
int main()
{
 	cin>>l>>r;
 	makepr();
 	for(int i=1;i<=k;i++)
 	{
 		j=l/pr[i];
 		if(j*pr[i]<l)j++;
 		if(j==1)j++;
 		for(;pr[i]*j<=r;j++)a[pr[i]*j-l]=1;
 	}
 	for(int i=0;i<=r-l;i++)if(!a[i])ans++;
 	cout<<ans;
	return 0;
}

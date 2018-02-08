#include<iostream>
using namespace std;
int a[24]={0},n;
long long ans;
void jia()
{
	a[1]++;
	for(int i=1;i<=a[0];i++){a[i+1]+=a[i]/2;a[i]=a[i]&1;}
	if(a[a[0]+1])a[0]++;
}
int chu()
{
	int k=0;ans=0;
	for(int i=a[0];i>=1;i--)
	{
		k=k*10+a[i];
		ans=ans*10+k/n;
		k%=n;
	}
	return k;
}
int main()
{
	cin>>n;
	while(a[0]<=25)
	{
		jia();
		if(!chu()){cout<<ans;return 0;}
	}
}
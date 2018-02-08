#include<iostream>
using namespace std;
int a[10000000]={0};
void chengdan(int a[],int num)
{
	if(num==0)return;
	for(int i=1;i<=a[0];i++)a[i]*=num;
	for(int i=1;i<=a[0];i++)
	{
 		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	if(a[a[0]+1]>=0)
	{
		a[0]++;
		while(a[a[0]]>=10)
		{
			a[0]++;
			a[a[0]]+=a[a[0]-1]/10;
			a[a[0]-1]%=10;
		}
	}
}
void chudan(int a[],int num)
{
	int d=0;
	for(int i=a[0];i>=1;i--)
	{
		d=d*10+a[i];
		a[i]=d/num;
		d=d%num;
	}
	while(a[0]>0&&a[a[0]]==0)a[0]--;
}
int main()
{
	int m,n;
	cin>>m>>n;
	a[0]=1;a[1]=1;
 	for(int i=1;i<=m;i++)
 	{
 		chengdan(a,n-m+i);
 		chudan(a,i);
 	}
 	for(int i=a[0];i>=1;i--)cout<<a[i];
	return 0;
}

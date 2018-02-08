#include<iostream>
#include<cstring>
using namespace std;
//struct shu(){int data;int code;};
int m=0;
void so1()
{
	int a[100];
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int k=0;
	for(int i=0;i<n;i++)
	{
		k=0;
		for(int j=0;j<i;j++)if(a[j]<a[i])k++;
		cout<<k<<" ";
	}
}
int find(int b[],int k) 
{
 int i=0,t=0;
 while(1)
 {
  if(b[i]==0)t++; 
  if(k==t){b[i]=1;return i;}
  i++;
  }
}
void so2()
{
	int a[100],b[100]={0},c[100];
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=n-1;i>=0;i--)
			c[i]=find(b,a[i]+1);
	for(int i=0;i<n;i++)cout<<c[i]<<" ";
}
int main()
{
	
	cin>>m;
	if(m==1)so1();
	if(m==2)so2();
 	
	return 0;
}

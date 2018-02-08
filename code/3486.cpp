#include<iostream>
using namespace std;
int n,c;
long long a[30005]={0},ans=0;
void heapdown()
{
	int i=1,j;
	while(i*2<=a[0])
	{
		if(i*2==a[0]||a[i*2]<a[i*2+1])j=i*2;
		else j=i*2+1;
		if(a[i]>a[j]){swap(a[i],a[j]);i=j;}
		else break;
	}
}
void heapup()
{
	int x=a[0];
	while(x>1&&a[x/2]>a[x]){swap(a[x/2],a[x]);x/=2;}
}
void setheap(int c)
{
	a[++a[0]]=c;
	heapup();
}
int del()
{
	int t=a[1];
	a[1]=a[a[0]--];
	heapdown();
	return t;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c);
		setheap(c);
	}
	int t1,t2;
	while(a[0]>1)
	{
		t1=del();t2=del();
		ans+=t1+t2;
		setheap(t1+t2);
	}
	cout<<ans<<endl;
	return 0;
}
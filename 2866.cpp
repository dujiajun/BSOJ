#include<iostream>
#include<cstdio>
using namespace std;
int a[1000001]={0},m;
void heapdown()
{
	int i=1,j,t;
	while(i*2<=a[0])
	{
		if(i*2==a[0]||a[i*2]>a[i*2+1])j=i*2;
		else j=i*2+1;
		if(a[i]<a[j]){swap(a[i],a[j]);i=j;}
		else break;
	}
}
void heapup()
{
	int i=a[0],t;
	while(i>1&&a[i]>a[i/2]){swap(a[i],a[i/2]);i=i/2;}
}
void setheap(int c)
{
	a[++a[0]]=c;heapup();
}
void del()
{
	a[1]=a[a[0]--];heapdown();
}
int main()
{
	int x,c,n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x==1){scanf("%d",&c);setheap(c);}
		if(x==2)del();
		if(x==3)printf("%d\n",a[1]);
	}
	return 0;
}
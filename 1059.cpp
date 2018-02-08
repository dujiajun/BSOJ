#include<iostream>
using namespace std;
int a[100001]={0};
void heapdown()
{
	int t,i=1,j;
	while(i*2<=a[0])
	{
		if(a[i*2]<a[i*2+1])j=i*2;
		else j=i*2+1;
		if(a[i]>a[j]){swap(a[i],a[j]);i=j;}
		else break;
	}
}
void heapup()
{
	int i=a[0];
	while(i>1&&a[i]<a[i/2]){swap(a[i],a[i/2]);i=i/2;}
}
void setheap(int c)
{
	a[0]++;
	a[a[0]]=c;
	heapup();
}
void del()
{
	a[1]=a[a[0]];
	a[0]--;
	heapdown();
}
int main()
{
	int n,c,k1,k2,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){cin>>c;setheap(c);}
	while(a[0]>1)
	{
		k1=a[1];del();
		k2=a[1];del();
		sum+=k1+k2;
		setheap(k1+k2);
	}
	cout<<sum<<endl;
	return 0;
}
#include<iostream>
using namespace std;
int n,m,c,a[1000005],lmax[1000005],lmin[1000005],rmax[1000005],rmin[1000005],bj;
int main()
{
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if((i-1)%m==0)
		{
			lmax[i]=a[i];
			lmin[i]=a[i];
		}
		if((i-1)%m!=0)
		{
			lmax[i]=max(lmax[i-1],a[i]);
			lmin[i]=min(lmin[i-1],a[i]);
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(i%m==0)
		{
			rmax[i]=a[i];
			rmin[i]=a[i];
		}
		if(i%m!=0)
		{
			rmax[i]=max(rmax[i+1],a[i]);
			rmin[i]=min(rmin[i+1],a[i]);
		}
	}
	for(int i=m,j,x,y;i<=n;i++)
	{
		j=i-m+1;
		x=max(lmax[i],rmax[j]);
		y=min(lmin[i],rmin[j]);
		if(x-y<=c)
		{
			printf("%d\n",j);
			bj=1;
		}
	}
	if(!bj)cout<<"NONE"<<endl;
	//return 0;
}
/*
7 2 0
0 1 1 2 3 2 2
*/
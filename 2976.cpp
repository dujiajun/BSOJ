#include<iostream>
using namespace std;
int a[100010]={0},n,m;
int judge(int mid)
{  
	int s=0,t=0;
   	for(int i=1;i<=n;i++)
   	{  
	   	if(a[i]>mid)return 0;
      	s+=a[i];
      	if(s>mid){s=a[i];t++;}
   	}
   	t++;
   	return(t<=m);
}
void erfen()
{  
	int l=1,r=0x7fffffff/2,mid;
   	while(l<r)
   	{  
	   	mid=(l+r)/2;
      	if(judge(mid))r=mid;else l=mid+1;
   	}
   	cout<<l;
}
int main()
{  
	scanf("%d%d",&n,&m);
  	for(int i=1;i<=n;i++)scanf("%d",a+i);
   	erfen();
   	return 0;
}
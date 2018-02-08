#include<iostream>
using namespace std;
int n, m,NT[100003],PR[100003],v[100003];
void Insert (int x,int y) 
{
	NT[y]=NT[x];
	PR[y]=x;
	NT[x]=y;
	PR[NT[y]]=y;
}
void Delete(int x) 
{
	if(v[x]) 
	{
		NT[PR[x]]=NT[x];
		PR[NT[x]]=PR[x];
		v[x]=0;
	}
}
int main() 
{
	cin>>n;
	NT[0]=n+1;v[1]=1;PR[n+1]=0;
	Insert(0,1);
	for(int i=2,x,p;i<=n;i++) 
	{
		scanf("%d%d",&x,&p);
		if(p==1)Insert(x,i);
		if(p==0)Insert(PR[x],i);
		v[i]= 1;
	}
	scanf("%d",&m);
	for (int i=1,x;i<=m;i++) 
	{
		scanf("%d",&x);
		Delete(x);
	}
	int x=0;
	while(1) 
	{
		if(x!=0)printf(" ");
		x=NT[x];if(x==n+1)break;
		printf("%d",x);
	}
	return 0;
}
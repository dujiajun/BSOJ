#include<iostream>
#include<cstring>
using namespace std;
int a[3][3],b[3][3],x[100]={0},ans=0;
long long n;
void mcopy(int a[][3],int b[][3])//copy d[][] to e[][];
{
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)a[i][j]=b[i][j];
}
void mcheng(int a[][3],int b[][3])
{
	int c[3][3]={0};
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)
	for(int k=1;k<=2;k++)c[i][j]=(c[i][j]+a[i][k]*b[k][j]%32768)%32768;
	mcopy(a,c);
}
int main()
{
	cin>>n;
	if(n==1||n==2)
	{
		cout<<1<<endl;
		return 0;
	}
	n-=2;x[0]=0;
	while(n){x[++x[0]]=n%2;n/=2;}
	a[1][1]=0;a[1][2]=1;a[2][1]=1;a[2][2]=1;
	mcopy(b,a);
	for(int i=x[0]-1;i>=1;i--)
	{
		mcheng(a,a);
		if(x[i]==1)mcheng(a,b);
	}
	ans=(a[1][2]+a[2][2])%32768;
	printf("%d\n",ans);
	return 0;
}
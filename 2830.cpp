#include<iostream>
#include<cstring>
using namespace std;
int a[3][3],b[3][3],A,B,n,x[100]={0},ans=0;
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
	for(int k=1;k<=2;k++)c[i][j]=(c[i][j]+a[i][k]*b[k][j])%7;
	mcopy(a,c);
}
int main()
{
	cin>>A>>B>>n;n-=2;
	while(n){x[++x[0]]=n%2;n/=2;}
	a[1][1]=A%7;a[1][2]=B%7;a[2][1]=1;a[2][2]=0;
	mcopy(b,a);
	for(int i=x[0]-1;i>=1;i--)
	{
		mcheng(a,a);
		if(x[i]==1)mcheng(a,b);
	}
	ans=(a[1][1]+a[1][2])%7;
	cout<<ans;
	return 0;
}
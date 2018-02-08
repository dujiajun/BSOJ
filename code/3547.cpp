#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct point{double x,y;}a[500],c[500];
int n,g,r,f[200][200]={0},map[200][200]={0};
inline double dis(double x1,double y1,double x2,double y2){return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);}
inline double dis(double x,double y,double A,double B,double C){return fabs(A*x+B*y+C)/sqrt(A*A+B*B);}
inline void getk(int p1,int p2,double &A,double &B,double &C)//两点式求直线方程Ax+By+C=0
{
	A=(a[p1].y-a[p2].y)/(a[p1].x-a[p2].x);
	B=-1;
	C=a[p1].y-(a[p1].y-a[p2].y)/(a[p1].x-a[p2].x)*a[p1].x;
}
bool checkline(int p1,int p2,int cir)
{
	double A,B,C,A1,A2,B2,B1,C1,C2;
	getk(p1,p2,A,B,C);
	if(dis(c[cir].x,c[cir].y,A,B,C)>r)return 1;
	else 
	{
		A1=dis(a[p1].x,a[p1].y,c[cir].x,c[cir].y);
		B1=dis(a[p2].x,a[p2].y,c[cir].x,c[cir].y);
		C1=dis(a[p1].x,a[p1].y,a[p2].x,a[p2].y);
		if(A1>B1+C1||B1>A1+C1)return min(A1,B1)>r*r;
		else return 0;
	}
}
int main()
{
	cin>>n>>g>>r;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	for(int i=1;i<=g;i++)cin>>c[i].x>>c[i].y;
	for(int i=1,bj=1;i<=n;i++)
	{
		for(int j=1;j<=i-2;j++)
		{
			if(i==n&&j==1||i==1&&j==n)continue;
			bj=1;
			for(int k=1;k<=g;k++)if(!checkline(i,j,k)){bj=0;break;}
			if(bj)map[i][j]=map[j][i]=1;
		}
		for(int j=i+2;j<=n;j++)
		{
			if(i==1&&j==n||i==n&&j==1)continue;
			bj=1;
			for(int k=1;k<=g;k++)if(!checkline(i,j,k)){bj=0;break;}
			if(bj)map[i][j]=map[j][i]=1;
		}	
	}
	for(int t=2;t<n;t++)
	for(int i=1;i<=n-t;i++)
	{
		int j=i+t;
		for(int k=i+1;k<j;k++)f[i][j]=max(f[i][j],f[i][k]+f[k][j]);
		f[i][j]+=map[i][j];
	}
	cout<<f[1][n]<<endl;
	return 0;
}
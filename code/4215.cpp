#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1005],b[1005],f[1005][1005][2],p,q;
int main()
{
	cin>>n;
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		if(x<0)a[++p]=-x; 
		if(x>0)b[++q]=x; 
	}
	sort(a+1,a+p+1);
	sort(b+1,b+q+1);
	for(int i=1;i<=p;i++)   
	{
		f[i][0][0]=f[i-1][0][0]+(a[i]-a[i-1])*(q+p-(i-1));
		f[i][0][1]=f[i][0][0]+a[i]*(q+p-(i-1));
	}
	for(int i=1;i<=q;i++)
	{
		f[0][i][1]=f[0][i-1][1]+(b[i]-b[i-1])*(p+q-(i-1));
		f[0][i][0]=f[0][i][1]+b[i]*(p+q-(i-1));
	}
	for(int i=1;i<=p;i++)
	for(int j=1;j<=q;j++)
	{
		f[i][j][0]=min(f[i-1][j][0]+(a[i]-a[i-1])*(q-j+p-(i-1)),f[i-1][j][1]+(b[j]+a[i])*(q-j+p-(i-1)));
		f[i][j][1]=min(f[i][j-1][0]+(b[j]+a[i])*(p-i+q-(j-1)),f[i][j-1][1]+(b[j]-b[j-1])*(p-i+q-(j-1)));
	}
	cout<<min(f[p][q][1],f[p][q][0])<<endl;
	return 0;
}
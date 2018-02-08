#include<iostream>
#include<algorithm>
using namespace std;

int g(int x,int y){if(y==0)return x;else return g(y,x%y);}
int a[15],i,j,k,f[70005]={0},m;
int main()
{
	int n;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	m=a[1];
	for(i=2;i<=n;i++)m=g(m,a[i]);
	if(m!=1){cout<<0<<endl;return 0;}
	sort(a+1,a+n+1);
	m=a[n]*a[n-1];f[0]=1;
	for(i=1;i<=n;i++)
		for(j=a[i];j<=m;j++)
			if(f[j-a[i]])f[j]=1;
	for(i=m;i;i--)if(!f[i])break;
	cout<<i<<endl;	
	return 0;
}
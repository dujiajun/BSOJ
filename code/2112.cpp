#include<iostream>
using namespace std;
const int M=0xfffffff;
int a[4000]={0},f[2000005]={0},k,n,m,i,j,maxx=0;
int main()
{
	cin>>k>>n;
	for(i=1;i<=n;i++){cin>>a[i];maxx=max(maxx,a[i]);}
	m=k*maxx;
	for(i=1;i<=m;i++)f[i]=M;
	for(i=1;i<=n;i++)
	{
		for(j=a[i];j<=m;j++)
		if(f[j-a[i]]<k&&f[j-a[i]]+1<f[j])
            f[j]=f[j-a[i]]+1; 
    }
	for(i=1;i<=m;i++)
		if(f[i]==M)break;
    cout<<i-1<<endl;
	return 0;
}
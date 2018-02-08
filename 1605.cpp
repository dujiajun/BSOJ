#include<iostream>
#include<cmath>
using namespace std;
int m[800]={0},k,n,i,j,s=0,maxx=0;
bool f[2005][2005]={false};

int main()
{
	cin>>n;
	for(i=1;i<=n;i++){cin>>m[i];s+=m[i];} 
	f[0][0]=true;
	for(k=1;k<=n;k++)
		for(i=s/2;i>=0;i--)
			for(j=s/2;j>=0;j--)
			{
				if(i-m[k]>=0)f[i][j]=f[i][j]||f[i-m[k]][j];
				if(j-m[k]>=0)f[i][j]=f[i][j]||f[i][j-m[k]];
			}
	double ans=0;
	for(i=0;i<=s/2;i++)
		for(j=0;j<=s/2;j++)
			if(f[i][j])
			{
				double p=s/2.0;
				double w=p*(p-i)*(p-j)*(p-(s-i-j));
				int c=s-i-j;
				if(i+j>c&&i+c>j&&j+c>i)ans=max(ans,sqrt(w)*100);
			} 
	if(ans==0)cout<<-1<<endl;
		else cout<<(int)(ans)<<endl;
	return 0;
}
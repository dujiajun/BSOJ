#include<iostream>
using namespace std;
int n,v,a[50],f[20005];
int main()
{
	cin>>v>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//f[a[i]]=1;
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
	for(int j=v;j>=a[i];j--)if(f[j-a[i]]||f[j]){f[j]=1;}
	for(int i=v;i>=0;i--)if(f[i])
	{
		cout<<v-i<<endl;
		break;
	}
	return 0;
}
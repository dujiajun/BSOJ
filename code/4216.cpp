#include<iostream>
using namespace std;
const long long Mod=12345678910ll;
int n,x,tot=0;
long long t[100005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(!x)t[++tot]=0;
		else
		{
			if(t[tot])t[tot-1]=(t[tot-1]+t[tot]*2)%Mod;
			else t[tot-1]++;  
			tot--;
		}
	}
	cout<<t[0]<<endl;
	return 0;  	
}
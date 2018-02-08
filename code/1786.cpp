#include<iostream>
using namespace std;
int n,a[20005],cir=0,len=0,vst[20005]={0},maxl=0,j;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		j=i;len=0;
		if(!vst[i])cir++;
		while(!vst[j]){vst[j]=1;j=a[j];len++;}
		maxl=max(maxl,len);
	}
	cout<<n-cir<<" ";
	if(maxl==1)cout<<0;
	if(maxl==2)cout<<1;
	if(maxl>2) cout<<2;
	return 0;
}
/* 
4
2
1
4
3
*/
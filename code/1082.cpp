#include<iostream>
#include<cstring>
using namespace std;
string s;
int f[500005]={0},h[500005]={0},t=1,i,j,k,ans=0;
void doit()
{
	memset(h,0,sizeof(h));memset(f,0,sizeof(f));h[1]=30;t=1;ans=0;
	for(i=0;i<s.length();i++){h[++t]=s[i]-'a'+1;h[++t]=30;}
	i=1,j=1,k=1;
	while(i<=t)
	{
		while(i-j>=0&&i+j<=t&&h[i-j]==h[i+j])j++;
		j--;f[i]=j;k=1;
		while(k<=j&&f[i-k]!=f[i]-k){f[i+k]=min(f[i-k],f[i]-k);k++;}
		i+=k;j=max(0,j-k);j=min(j,t-i);
	}
	for(i=1;i<=t;i++)
	{
		j=f[i];
		if(j>ans)ans=j;
	}
	cout<<ans<<endl;
}
int main()
{
	while(cin>>s)doit();
	return 0;
}
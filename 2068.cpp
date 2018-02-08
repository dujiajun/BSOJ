#include<iostream>
using namespace std;
char s[50005];
int f[50005]={0},h[50005]={0},t=1,m=1,b[50005]={0},i,j,k,ans=0,st,ed;
int main()
{
	while((s[m]=getchar())!=EOF)m++;
	h[1]=30;
	for(i=1;i<=m;i++)
	{
		if(s[i]>='a'&&s[i]<='z'){h[++t]=s[i]-'a';b[t]=i;h[++t]=30;}
		if(s[i]>='A'&&s[i]<='Z'){h[++t]=s[i]-'A';b[t]=i;h[++t]=30;}
	}
	i=1,j=1,k;
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
		if(j>ans){ans=j;st=b[i-j+1];ed=b[i+j-1];}
	}
	cout<<ans<<endl;
	for(i=st;i<=ed;i++)cout<<s[i];
	return 0;
}
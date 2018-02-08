#include<iostream>
#include<map>
using namespace std;
map<char,int>s;
int n,t,cnt,st,bian,bj,d[1005],a[1005][1005],cir[100005];
char id[1005];
char get_char()
{
	char ch;
	while(1)
	{
		ch=getchar();
		if(ch>='a'&&ch<='z')return ch;
		if(ch>='A'&&ch<='Z')return ch;
	}
}
void dfs(int x,int dp)
{
	cir[dp]=x;
	if(dp==bian+1)
	{
		for(int i=1;i<=bian+1;i++)cout<<id[cir[i]];
		bj=1;
		return;
	}
	for(int i=1;i<=t;i++)
	if(a[x][i]||a[i][x])
	{
		a[x][i]=a[i][x]=0;
		dfs(i,dp+1);
		a[x][i]=a[i][x]=1;
		if(bj)return;
	}
}
int main()
{
	cin>>n;char c1,c2;
	for(char i='A';i<='Z';i++){s[i]=++t;id[t]=i;}
	for(char i='a';i<='z';i++){s[i]=++t;id[t]=i;}
	for(int i=1;i<=n;i++)
	{
		c1=get_char();c2=get_char();
		d[s[c1]]++;d[s[c2]]++;
		a[s[c1]][s[c2]]=1;
		a[s[c2]][s[c1]]=1;
		bian++;
	}
	for(int i=t;i>=1;i--)if(d[i]%2==1){cnt++;st=i;}
	if(cnt!=0&&cnt!=2)
	{
		cout<<"No Solution"<<endl;
		return 0;
	}
	if(cnt==0)
	{
		for(int i=1;i<=t;i++)if(d[i]){dfs(i,1);break;} 
		return 0;
	}
	dfs(st,1);
	return 0;
}
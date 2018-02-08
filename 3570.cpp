#include<iostream>
#include<cmath>
using namespace std;
int n=0,c,m,f[200005][25]={0};
void st()
{
	int t=log2(n);
	for(int j=1;j<=t;j++)
	for(int i=1;i+(1<<j)-1<=n;i++)f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int ask(int l,int r)
{
	int t=log2(r-l+1);
	return max(f[l][t],f[r-(1<<t)+1][t]);
}
int main()
{
	cin>>m;
	while(1)
	{
		scanf("%d",&c);
		if(c==-1)break;
		f[++n][0]=c;
	}
	st();
	for(int i=m;i<=n;i++)printf("%d\n",ask(i-m+1,i));
	return 0;
}
/*
3
10
11
10
0
0
0
1
2
3
2
-1
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int w,h,m;
long long f[13][1<<13];
bool check(int a,int b)
{
	int i=1;
	while(i<(1<<h))
	{
		if(((a&i)==0)&&((b&i)==0))return 0;
		if((a&i)&&(b&i))
		{
			if((a&(i<<1))&&(b&(i<<1))){i<<=2;continue;}
			else return 0;
		}
		i<<=1;
	}
	return 1;
}
int ok(int x)
{
	int cnt=0;
   	while(x>0)
   	{  
	   	if(x%2)cnt++;
        else if(cnt%2)return 0;
      	x>>=1;
   	}
   	if(cnt%2)return 0;
   	return 1;
}
void dp()
{
	m=1<<h;
	memset(f,0,sizeof(f));
	for(int i=0;i<m;i++)if(ok(i))f[1][i]=1;
	for(int i=2;i<=w;i++)
	for(int j=0;j<m;j++)
	for(int k=0;k<m;k++)
	if(check(j,k))f[i][j]+=f[i-1][k];
}
int main()
{
	while(cin>>w>>h)
	{
		if((w*h)%2){cout<<0<<endl;continue;}
		if(w<h)swap(w,h);
		dp();
		cout<<f[w][m-1]<<endl;
	}
	return 0;
}
/*
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
*/
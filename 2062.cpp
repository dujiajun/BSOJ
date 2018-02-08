#include<iostream>
using namespace std;
int n;
struct tile
{char data[15][15];}a,b,c;
bool check(tile x,tile y)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(x.data[i][j]!=y.data[i][j])return false;
	return true;
}
tile solve(int x,tile bf,int k)
{
	tile tmp;
	switch(x)
	{
		case 1:
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					tmp.data[j][n-i+1]=bf.data[i][j];
			return tmp;
		case 2:
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					tmp.data[n-i+1][n-j+1]=bf.data[i][j];
			return tmp;
		case 3:
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					tmp.data[n-j+1][i]=bf.data[i][j];
			return tmp;
		case 4:
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					tmp.data[i][n-j+1]=bf.data[i][j];
			return tmp;
		case 5:
			tmp=solve(4,bf,1);
			if(k==1)tmp=solve(1,tmp,1);
			if(k==2)tmp=solve(2,tmp,1);
			if(k==3)tmp=solve(3,tmp,1);
			return tmp;
	}
}

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)cin>>a.data[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)cin>>b.data[i][j];
}
int main()
{
	int i;
	init();
	for(i=1;i<=5;i++)
	{
		if(i<=4)
		{
			c=solve(i,a,1);
			if(check(c,b)){cout<<i<<endl;return 0;}
		}
		if(i==5)
			for(int j=1;j<=3;j++)
			{
				c=solve(5,a,j);
				if(check(b,c)){cout<<5<<endl;return 0;}
			}
	}
	if(check(a,b)){cout<<6<<endl;return 0;}
	cout<<7<<endl;
	return 0;
}
/*
3
@-@ 
---
@@-
@-@
@--
--@
*/
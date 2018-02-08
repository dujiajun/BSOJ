#include<iostream>
using namespace std;
int fh[4]={0,1,0,-1};
int fl[4]={1,0,-1,0};

int main(){
	int n;
	cin>>n;
	int a[102][102]={0},k=1,x=0,y=n,fx=1,newx,newy;
	for(int i=0;i<=n+1;i++){a[i][0]=1;a[0][i]=1;a[n+1][i]=1;a[i][n+1]=1;}
	while(true)
	{
		if(k>n*n)break;
		newx=x+fh[fx];
		newy=y+fl[fx];
		if(a[newx][newy]==0)
		{
			a[newx][newy]=k;
			x=newx;y=newy;k++;
		}
		else fx=(fx+1)%4;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}
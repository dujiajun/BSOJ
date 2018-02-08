#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int map[100][100]={0},vst[100]={0};

int main()
{
	int n;
	cin>>n;
	int t=pow(2,n);
	for(int i=1;i<=t-1;i++)
	{
		memset(vst,0,sizeof(vst));
		for(int x=1;x<=t;x++)
		for(int y=1;y<=t;y++)
		{
			if(x!=y&&!vst[x]&&!vst[y]&&!map[x][y]&&!map[y][x])
			{
				cout<<x<<"-"<<y<<" ";
				map[x][y]=map[y][x]=1;
				vst[x]=vst[y]=1;
			}
		}
		cout<<endl;
	}
	
	return 0;
}
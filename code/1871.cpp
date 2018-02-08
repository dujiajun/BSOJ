#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool hash[400000]={0};
int v[10]={0},s=0;
struct node{int data[4][4],step;}a[400000];
int number(int data[][4])
{
	int value=1,f=0,x[10];
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++){f++;x[f]=data[i][j];}
	
	for(int i=1;i<=9;i++)
	{
		f=0;
		for(int j=i+1;j<=9;j++)
			if(x[i]>x[j])f++;
		value+=v[i+1]*f;
	}
	return value;
}
int bfs()
{
	int head=-1,tail=0;
	while(head<=tail)
	{
		head++;
		for(int i=1;i<=2;i++)
		{
			int m[4][4];
			for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
			m[j][k]=a[head].data[j][k];
			if(i==1)
			{
				int tmp=m[1][1];m[1][1]=m[2][1];m[2][1]=m[3][1];
				m[3][1]=m[3][2];m[3][2]=m[3][3];m[3][3]=m[2][3];
				m[2][3]=m[1][3];m[1][3]=m[1][2];m[1][2]=tmp;
			}
			else
			{
				int tmp=m[2][1];m[2][1]=m[2][3];m[2][3]=m[2][2];m[2][2]=tmp; 
			}

			int z=number(m);
			if(z==1){s++;cout<<a[head].step+1<<endl;return 1;}
			if(!hash[z])
			{
				hash[z]=true;
				tail++;
				for(int j=1;j<=3;j++)
				for(int k=1;k<=3;k++)a[tail].data[j][k]=m[j][k];
				a[tail].step=a[head].step+1;
			}
		}
	}
	return -1; 
}
void init()
{
	memset(hash,0,sizeof(hash));
	for(int i=2;i<=3;i++)
	for(int j=1;j<=3;j++)cin>>a[0].data[i][j];
	a[0].step=0;
	int w=number(a[0].data);
	hash[w]=true;
}
int main()
{
	int x=1;
	memset(v,0,sizeof(v));
	for(int i=9;i>=1;i--){x*=(10-i);v[i]=x;}
	while(cin>>a[0].data[1][1]>>a[0].data[1][2]>>a[0].data[1][3])
	{
		init();
		if(bfs()==-1)cout<<"UNSOLVABLE"<<endl;
	}
	return 0;
}
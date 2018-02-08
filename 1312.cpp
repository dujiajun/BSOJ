#include<iostream>
using namespace std;
bool hash[400000]={0};
int final=0;
struct node{int data[4][4],c;}n[400000];
const int f[9]={0,40320,5040,720,120,24,6,2,1};
const int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
int number(int data[][4])
{
	int sum=0,t,a[10];
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
	a[(i-1)*3+j]=data[i][j];
	for(int i=1;i<9;i++)
	{
		t=0;
		for(int j=i+1;j<=9;j++)
			if(a[i]>a[j])t++;
		sum+=f[i]*t;
	}
	return sum;
}
void bfs()
{
	node tmp;
	int h=1,t=1,num,x,y;
	num=number(n[1].data);
	if(num==final){cout<<n[1].c;return;}
	hash[num]=true;
	while(h<=t)
	{
		for(int i=1;i<4;i++)
			for(int j=1;j<4;j++)
				if(n[h].data[i][j]==0){x=i;y=j;break;}
		for(int i=1;i<=4;i++)
		{
			tmp=n[h];
			if(x+dx[i]>0&&x+dx[i]<4&&y+dy[i]>0&&y+dy[i]<4)
			{
				swap(tmp.data[x][y],tmp.data[x+dx[i]][y+dy[i]]);
				num=number(tmp.data);tmp.c++;
				if(num==final){cout<<tmp.c;return;}
				if(hash[num]==false){n[++t]=tmp;hash[num]=true;}
			}
		}
		h++;
	}
	cout<<-1<<endl;
	
}
int main()
{
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)cin>>n[1].data[i][j];
	n[1].c=0;
	bfs();
	return 0;
}
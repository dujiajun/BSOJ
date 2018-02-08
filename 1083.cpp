#include<iostream>
using namespace std;
int n,m,p,father[5005];
int getfather(int u)
{
	if(father[u]==u)return u;
	father[u]=getfather(father[u]);
	return father[u];
}
void judge(int x,int y)
{
	int f1=getfather(x),f2=getfather(y);
	if(f1!=f2)father[f1]=f2;
}
void print(int x,int y)
{
	int f1=getfather(x),f2=getfather(y);
	if(f1==f2)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
void init()
{
	int a,b;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=1;i<=m;i++){cin>>a>>b;judge(a,b);}
	for(int i=1;i<=p;i++){cin>>a>>b;print(a,b);}
}
int main()
{
	init();
	return 0;
} 
/*
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6
*/
#include<iostream>
using namespace std;
int a[35][2],check[35]={0},n;
void change()
{
	int x,b;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=1;;j++)
		{
			cin>>x;
			check[x]=1;
			if(x==0)break;
			if(j==1)a[i][0]=x;
			else a[b][1]=x;
			b=x;
		}
	}
}
void bl(int root,int k)
{
	if(k==1)cout<<char(root+'A'-1);
	if(a[root][0])bl(a[root][0],k);
	if(k==2)cout<<char(root+'A'-1);
	if(a[root][1])bl(a[root][1],k);
	if(k==3)cout<<char(root+'A'-1);
}
int main()
{
	int root;
	change();
	for(int i=1;i<=n;i++)if(check[i]==0)root=i;
	bl(root,1);cout<<endl;
	bl(root,2);cout<<endl;
	bl(root,3);
	return 0;
}
/*
7
'A' 2 3 4 0
'B' 5 0
'C' 6 7 0
'D' 0
'E' 0
'F' 0
'G' 0
*/